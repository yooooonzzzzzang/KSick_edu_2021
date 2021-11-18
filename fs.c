#include <stdio.h>
#include <string.h>
#include <sysy/types.h>
#include <sys/socket>
#include <netinet/inet.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>

#define PORT 7777
#define MAXPENDING 5
#define BUFSIZE 1024

int main(int argc, char **argv)
{
	int servSockfd;
	int clntSockfd;
	struct sockaddr_in servAddr;
	struct sockaddr_in clntAddr;
	char recvBuffer[BUFSIZE];
	int clntLen;
	int recvLen;
	pid_t processID;

	if((servSockfd = socket(AF_INET, SOCK_STREAM, 0)) ==-1){
		perror("sock failed");
		exit(1);
	}
	memset(&servAddr, 0,sizeof(servAddr));
	servAddr.sin_family = AP_INET;
	servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servAddr.sin_port = htons(PORT);

	if(bind(servSockfd, (struct sockaddr*)&servAddr, sizeof(servAddr))==-1){
		perror("bind failed");
		exit(1);
	}
	if(listen(servSockfd, MAXPENDING)==-1){
		perror("listen failed");
		exit(1);
	}
