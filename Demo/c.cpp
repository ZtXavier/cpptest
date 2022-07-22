#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include<ctype.h>
#include<arpa/inet.h>
#define PORT	 8088
#define MAXLINE 1024

int main(int argc, char **argv)
{
	int sockfd;
	char *ser = argv[1];
	char *buff = argv[2];
	struct sockaddr_in	 server;
	int ret;
	int  len;

	if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
		perror("socket");
		return -1;
	}

	memset(&server, 0, sizeof(server));

	server.sin_family = AF_INET;
	server.sin_port = htons(PORT);
	server.sin_addr.s_addr = inet_addr(ser);
	while (1) {
		sendto(sockfd, (const char *)buff, strlen(buff),
			MSG_CONFIRM, (const struct sockaddr *) &server, sizeof(server));
		printf("%s\n", buff);

		sleep(1);
	}

	close(sockfd);
	return 0;
}



 


