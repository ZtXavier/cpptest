#include"Head.hpp"
#include<memory>
#include<vector>
#include<map>
#include<functional>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/epoll.h>
#include<errno.h>

void my_error(const char *err)
{
    perror(err);
    exit(0);
}
using namespace std::placeholders;

class EchoServer
{
    public:
        EchoServer(int port):port_(port),base_(new Reactor)
        {

        }
        void start()
        {
            setsock();
            base_->loop();
        }

        void setsock()
        {
            int skfd = socket(AF_INET,SOCK_STREAM | SOCK_NONBLOCK,0);
            if(skfd < 0)
            {
                my_error("socket error");
            }
            auto handlerPtr = std::make_shared<Handler>(skfd);
            handlerlist_[skfd] = handlerPtr;
            int reuse = 1;
            setsockopt(skfd,SOL_SOCKET,SO_REUSEPORT,&reuse,sizeof(reuse));
            sockaddr_in addr;
            bzero(&addr,sizeof(addr));
            addr.sin_family = AF_INET;
            addr.sin_port = htons(port_);
            addr.sin_addr.s_addr = htonl(INADDR_ANY);
            int ret = bind(handlerPtr->retfd(),(sockaddr*)&addr,sizeof(addr));
            if(ret < 0)
            {
                my_error("bind error\n");
            }
            ret = listen(handlerPtr->retfd(),16);
            if(ret < 0)
            {
                my_error("listen error");
            }
            // 在此时accept套接字并链接
            handlerPtr->setReadCallback(std::bind(&EchoServer::acceptConn,this,_1));
            handlerPtr->enableRead();
            base_->registerHandler(handlerPtr.get());
        }
    private:
        void acceptConn(int fd)
        {
            printf("accepting...\n");
        
            int ctfd = accept4(fd,NULL,NULL,SOCK_NONBLOCK);
            if(ctfd < 0)
            {
                my_error("accept error");
            }
            auto connHandler = std::make_shared<Handler>(ctfd);
            handlerlist_[ctfd] = connHandler;
            connHandler->setReadCallback(std::bind(&EchoServer::readdata,this,_1));
            connHandler->enableRead();
            base_->registerHandler(connHandler.get());
        }

        void readdata(int fd)
        {
            printf("reading...\n");
            auto rhandler = handlerlist_[fd];
            int nbytes = read(fd,rhandler->buff(),4096);
            if(nbytes > 0)
            {
                rhandler->buff()[nbytes] = '\0';
                printf("have read:%s\n",rhandler->buff());
                rhandler->setLen(nbytes);
                rhandler->setWriteCallback(std::bind(&EchoServer::senddata,this,_1));
                rhandler->enableWrite();
                base_->registerHandler(rhandler.get());
            }
            else if(nbytes == 0)
            {
                printf("close fd\n");
                close(fd);
                base_->removeHandler(rhandler.get());
                handlerlist_.erase(fd);
            }
            else
            {       
                close(fd);
                printf("read error\n");
                base_->removeHandler(rhandler.get());
                handlerlist_.erase(fd);
            }
        }

        void senddata(int fd)
        {
            auto shandler = handlerlist_[fd];
            int nbytes = write(fd,shandler->buff(),shandler->length());
            if(nbytes > 0)
            {
                shandler->setReadCallback(std::bind(&EchoServer::readdata,this,_1));
                shandler->enableRead();
                base_->registerHandler(shandler.get());
            }
            else
            {
                printf("write error");
                close(fd);
                base_->removeHandler(shandler.get());
                handlerlist_.erase(fd);
            }
        }

    private:
        int port_;
        std::string ip_;
        std::unique_ptr<Reactor> base_;
        std::map<int,std::shared_ptr<Handler>> handlerlist_;
};


int main()
{
    EchoServer server(9999);
    server.start();
    return 0;
}