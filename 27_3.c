#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#define PORT 7777       
#define BUFSIZE 1024    
int main(int argc, char**argv)
{
	int sockfd;
	struct sockaddr_in servAddr;
	struct sockaddr_in clntAddr;
	char recvBuffer[BUFSIZE];
	int clntLen;
	int recvLen;

	if((sockfd=socket(AF_INET,SOCK_DGRAM,0)) ==-1){
		perror("sock failed");
		exit(1);
	}
	
       memset(&servAddr,0,sizeof(servAddr));
	servAddr.sin_family = AF_INET;
 	servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servAddr.sin_port = htons(PORT);

	if(bind(sockfd,(struct sockaddr*)&servAddr, sizeof(servAddr)) == -1){
	perror("bind failed");
	exit(1);
	}

	while(1) {
	clntLen = sizeof(clntAddr);
	if((recvLen=recvfrom(sockfd, recvBuffer, BUFSIZE-1,0,(struct sockaddr*)&clntAddr, &clntLen)) == -1){
		perror("recvfrom failed");
		exit(1);
	}
	recvBuffer[recvLen] = '\0';
	printf("Received : %s\n", recvBuffer);

	if(sendto(sockfd, recvBuffer, recvLen,0, (struct sockaddr*)&clntAddr, sizeof(clntAddr))!=recvLen){
		perror("sendto failed");
		exit(1);
	}
	}
}

