#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <signal.h>
#include <stdlib.h>
#define SIZE 124

struct{
	long type;
	char data[SIZE];
}msg_data;

int main(int argc, char**argv)
{
	int msqid;
	struct msqid_ds msg_stat;

	if((msqid =msgget((key_t)1234, IPC_CREAT|0666) ==-1)){
		perror("msgget failed");
		exit(1);
	}
	if((msgrcv(msqid, &msg_data, SIZE,0,0) == -1)){
		perror("msgrcv failed");
		exit(1);
	}

	printf("dta read from message queue : %s\n", msg_data.data);
	if(msgctl(msqid, IPC_STAT, &msg_stat)==-1){
		perror("msgctl failed");
		exit(1);
	}
	kill(msg_stat.msg_lspid, SIGINT);

	exit(0);
}

