#include<iostream>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<cstdio>
#include<string>

#define CHECK_RET(q) if((q) == false) {return -1;}

class UDPSocket
{
    public:
    UDPSocket():_sockfd(-1) {}
    bool Socket()
    {
        _sockfd = socket(AF_INET,SOCK_DGRAM,0);
        if(_sockfd < 0)
        {
            perror("socket error");
            return false;
        }
        return true;
    }

    bool Bind(const std::string &ip,int port)
    {
        struct sockaddr_in addr;
        addr.sin_family = AF_INET;
        addr.sin_port = htons(8000);
        addr.sin_addr.s_addr = inet_addr("127.0.0.1");
        socklen_t sklen = sizeof(struct sockaddr_in);
        if(bind(_sockfd,(struct sockaddr*)&addr,sklen) < 0)
        {
            perror("bind error\n");
            return false;
        }
        return true;
    }

    bool Send(const std::string &data,const std::string &ip,int port)
    {
        struct sockaddr_in peeraddr;
        peeraddr.sin_family = AF_INET;
        peeraddr.sin_port = htons(port);
        peeraddr.sin_addr.s_addr = inet_addr(ip.c_str());
        socklen_t sklen = sizeof(struct sockaddr_in);
        int ret = sendto(_sockfd,&data[0],data.size(),0,(struct sockaddr*)&peeraddr,sklen);
        if(ret < 0)
        {
            perror("sendto error\n");
            return false;
        }
        return true;
    }

    bool Recv(std::string *buf,std::string *ip = NULL,int *port = NULL)
    {
        struct sockaddr_in peeraddr;
        bzero(&(peeraddr),sizeof(struct sockaddr_in));
        peeraddr.sin_family = AF_INET;
        peeraddr.sin_addr.s_addr = INADDR_ANY;
        peeraddr.sin_port = htons(9002);
        socklen_t sklen = sizeof(struct sockaddr_in);
        char tmp[4096] = {0};
        int ret = recvfrom(_sockfd,tmp,4095,0,(struct sockaddr*)&peeraddr,&sklen);
        if(ret < 0)
        {
            perror("recvfrom error");
            return false;
        }
        buf->assign(tmp,ret);
        if(ip != NULL)
        {
            *ip = inet_ntoa(peeraddr.sin_addr);
        }
        if(port != NULL)
        {
            *ip = ntohs(peeraddr.sin_port);
        }
        return true;
    }

    bool Closefd()
    {
        if(_sockfd > 0)
        {
            close(_sockfd);
            _sockfd = -1;
        }
        return true;
    }

    // bool setopt()
    // {
    //     struct timeval tv_out;
    //     tv_out.tv_sec = 3;
    //     tv_out.tv_usec = 0;
    //     setsockopt(_sockfd,SOL_SOCKET,SO_RCVTIMEO,&tv_out,sizeof(tv_out));
    //     return true;
    // }

    private:
        int _sockfd;
};

int main(int argc,char*argv[])
{
    if(argc < 3)
    {
        std::cout << "input ip port" << std::endl;
        return -1;
    }
    std::string srv_ip = argv[1];
    int srv_port =atoi(argv[2]);
    UDPSocket sock;
    CHECK_RET(sock.Socket());
    // sock.setopt();
    while(1)
    {
        std::string buf;
        std::cout << "client input\n";
        std::cin >> buf;
        CHECK_RET(sock.Send(buf,srv_ip,srv_port));
        buf.clear();
        CHECK_RET(sock.Recv(&buf));
        std::cout << "server response:" << buf << std::endl;
    }
    sock.Closefd();
    return 0;
}