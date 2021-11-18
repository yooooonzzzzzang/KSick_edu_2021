#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>
#define PORT 7777       
#define BUFSIZE 1024 

void signalHandler(int signo);
int sockfd;

int main(int argc, char *argv[])
{
	struct sockaddr_in servAddr;
	char sendBuffer[BUFSIZE], recvBuffer[BUFSIZE];
	int recvLen;
	pid_t pid;

	if(argc != 2){
		fprintf(stderr, "Usage : %s IP_address\n", argv[0]);
		exit(1);
	}

       if((sockfd=socket(AF_INET, SOCK_STREAM,0)) ==-1){
       		perror("sock failed");
		exit(1);
       }

	if(connect(sockfd, (struct sockaddr*)&servAddr, sizeof(servAddr)) ==-1){
	 perror("connect failed");
 		exit(1);
	}
	switch(pid=fork()){
		case -1:
			perror("fork failed");
			exit(1);
		case 0:
			
		signal(SIGINT, signalHandler);
		while(1){
		
		if((recvLen=recv(sockfd, recvBuffer, BUFSIZE, 0 )) ==-1){
			perror("recv failed");
			exit(1);
		}

		recvBuffer[recvLen] = '\0';
	
		printf("%s\n", recvBuffer);
		}
		break;
	
		default:

		while(1){
			fgets(sendBuffer, BUFSIZE, stdin);
			if(!strncmp(sendBuffer, "quit", 4)){
				kill(pid, SIGINT);
				break;
			}
			if(send(sockfd, sendBuffer, strlen(sendBuffer), 0)!=strlen(sendBuffer)) {
				perror("send failed");
				exit(1);
			}
		}
	}
	close(sockfd);
	exit(0);
}

void signalHandler(int signo)
{
	close(sockfd);
	exit(0);
}

















