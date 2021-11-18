#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdlib.h>
#define PORT 7777       

#define BUFSIZE 1024    
int main(int argc, char *argv[])
{
	int sockfd;
	struct sockaddr_in servAddr;
	char sendBuffer[BUFSIZE], recvBuffer[BUFSIZE];
	int recvLen;

	if(argc!=2){
		fprintf(stderr, "usage: %s IP_address\n", argv[0]);
		exit(1);
	}
	
	if((sockfd=socket(AF_INET, SOCK_STREAM,0)) == -1){
		perror("sock failed");
		exit(1);
	}
	memset(&servAddr, 0, sizeof(servAddr));

	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = inet_addr(argv[1]);
	servAddr.sin_port = htons(PORT);

	if(connect(sockfd, (struct sockaddr*)&servAddr, sizeof(servAddr))==-1){
		perror("connect failed");
		exit(1);
	}
	while(1){
		printf("Input sending message ==> ");
		fgets(sendBuffer, BUFSIZE, stdin);
		if(!strncmp(sendBuffer, "quit",4))
			break;
	       if(send(sockfd, sendBuffer, strlen(sendBuffer),0) != strlen(sendBuffer)){
	       perror("send failed");
exit(1);
	       }
	       if((recvLen=recv(sockfd, recvBuffer, BUFSIZE-1,0)) <= 0){
		       perror("recv failed");
		       exit(1);
	       }
	       recvBuffer[recvLen] = '\0';
	       printf("Received: %s\n",recvBuffer);
	}
	close(sockfd);
	exit(0);
}

