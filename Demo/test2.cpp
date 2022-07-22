#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>

void start_server(__uint32_t host) 
{
    int listenfd, connfd;
    struct sockaddr_in servaddr;
    int optval = 1;
    socklen_t len = sizeof(optval);
    socklen_t ll = sizeof(servaddr);

    if( (listenfd = socket(AF_INET, SOCK_STREAM, 0)) == -1 ){
        goto ERROR;
    }
    getsockopt(listenfd,SOL_SOCKET,SO_REUSEPORT,&optval,&len);
    
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = host;
    servaddr.sin_port = htons(6666);

    if(bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) == -1){
        goto ERROR;
    }

    if(listen(listenfd, 10) == -1) {
        goto ERROR;
    }
        for(;;)
        {
            accept(listenfd,(sockaddr*)&servaddr,&ll);
        }
    ERROR:
        printf("bind socket error: %s(errno: %d)\n", strerror(errno), errno);


}
int main()
{
   start_server(htonl(INADDR_ANY));
   return 0;
}