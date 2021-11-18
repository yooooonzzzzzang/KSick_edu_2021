#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#define PORT 7777
#define MAXPENDING 5
#define BUFSIZE 1024

int main(int argc, char**argv)
{
	int servSockfd;
	int clntSockfd;
	struct sockaddr_in servAddr;
	struct sockaddr_in clntAddr;
	char recvBuffer[BUFSIZE];
	char sendBuffer[BUFSIZE];
	int clntLen;
	int recvLen;

	if((servSockfd=socket(AF_INET, SOCK_STREAM, 0)) ==-1){
		perror("sock failed");
		exit(1);
	}
	memset(&servAddr,0, sizeof(servAddr));
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr=htonl(INADDR_ANY);
	servAddr.sin_port = htons(PORT);

	if(bind(servSockfd, (struct sockaddr*)&servAddr, sizeof(servAddr))==-1){
		perror("bind failed");
		exit(1);
	}
	if(listen(servSockfd, MAXPENDING) ==-1){
		perror("listen failed");
		exit(1);
	}
	while(1){
		clntLen = sizeof(clntAddr);
		if((clntSockfd=accept(servSockfd, (struct sockaddr*)&clntAddr, &clntLen))==-1){
			perror("accept failed");
			exit(1);
		}
		printf("client is in\n");
		switch(fork()){
			case -1:
				perror("fork failed");
				exit(1);
			case 0:
				close(servSockfd);
				while(1){
					if((recvLen=recv(clntSockfd, recvBuffer, BUFSIZE, 0))==-1){
						perror("recv failed");
						exit(1);
					}
					if(recvLen ==0)
						break;


					recvBuffer[recvLen] = '\0';
					printf("%s\n", recvBuffer);
				}
				close(clntSockfd);
				exit(0);

			default:
				while(1){
					fgets(sendBuffer, BUFSIZE, stdin);
					if(send(clntSockfd, sendBuffer, strlen(sendBuffer),MSG_NOSIGNAL)!=strlen(sendBuffer)){
						if(errno==EPIPE){
							printf("clinet is out\n");
							break;
						}
						perror("send failed");
						exit(1);
					}
				}
		}
		close(clntSockfd);
	}
}


			
