#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT	 8088
#define MAXLINE 1024

int main(int argc, char **argv)
{
	int sockfd;
	char buffer[MAXLINE];
	struct sockaddr_in server, client;
	int optval = 1;
    socklen_t len;
	int ret;

	memset(&server, 0, sizeof(server));
	memset(&client, 0, sizeof(client));

	if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
		perror("socket");
		return -1;
	}
	if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEPORT, &optval, sizeof(optval)) < 0) {
		perror("bind");
		return -1;
	}

	server.sin_family = AF_INET;
	server.sin_port = htons(PORT);
	server.sin_addr.s_addr = INADDR_ANY;

	if (bind(sockfd, (const struct sockaddr *)&server, sizeof(server)) < 0) {
		perror("bind");
		return -1;;
	}
    int i = 0;
	while (1) {
		ret = recvfrom(sockfd, (char *)buffer, MAXLINE,
				MSG_WAITALL, ( struct sockaddr *) &client, &len);
		buffer[ret] = '\0';
		printf("recv :%s\n", buffer);
	}

	return 0;
}
