#include<iostream>
#include<unistd.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<string.h>
#include<fcntl.h>

int main(int argc,char *argv[])
{
    if(argc < 3)
    {
        std::cout << "udp port = 9001 ";
        return -1;
    }
    char* srv_ip = argv[1];
    std::cout << srv_ip;
    int srv_port = atoi(argv[2]);
    std::cout << srv_port;
    int sockfd = socket(AF_INET,SOCK_DGRAM,0);
    if(sockfd < 0)
    {
        perror("sockfd error\n");
        return -1;
    }
    struct sockaddr_in addr;
    bzero(&(addr),sizeof(struct sockaddr_in));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(srv_port);
    addr.sin_addr.s_addr = INADDR_ANY;
    socklen_t  sklen = sizeof(addr);
    int  ret = bind(sockfd,(struct sockaddr*)&addr,sklen);
    if(ret < 0)
    {
        perror("bind error\n");
        return -1;
    }
    // struct timeval tv_out;
    // tv_out.tv_sec = 10;
    // tv_out.tv_usec = 0;
    // setsockopt(sockfd,SOL_SOCKET,SO_RCVTIMEO,&tv_out,sizeof(tv_out));
    // int flag = fcntl(sockfd,F_SETFL,0);
    // fcntl(sockfd,F_SETFL,flag | O_NONBLOCK);
    while(1)
    {
        char buf[4096] = {0};
        struct sockaddr_in client_addr;
        sklen = sizeof(client_addr);
        ret = recvfrom(sockfd,buf,4095,0,(struct sockaddr*)&client_addr,&sklen);
        if(ret < 0)
        {
            // close(sockfd);
            perror("recvfrom error");
            return -1;
        }
        printf("%s:%d - %s\n",inet_ntoa(client_addr.sin_addr),ntohs(client_addr.sin_port),buf);
        fflush(stdout);
        printf("server input:\n");
        memset(buf,0,sizeof(buf));
        scanf("%s",buf);
        ret = sendto(sockfd,buf,strlen(buf),0,(struct sockaddr*)&client_addr,sklen);
        if(ret < 0)
        {
            close(sockfd);
            perror("sendof error");
            return -1;
        }
    }
    close(sockfd);
    return 0;
}



