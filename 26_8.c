#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#define SIZE 1024
#include <stdlib.h>

int main(int argc, char**argv)
{
	struct check_data{
		int check;
		char data[SIZE];
	}*shared_data;
	int shmid;
	void *shmaddr;
	char buffer[SIZE];

	if((shmid=shmget((key_t)1234,SIZE, IPC_CREAT|0666)) == -1){
		perror("shimid failed");
		exit(1);
	}
	if((shmaddr=shmat(shmid, (void *)0,0)) == (void *)-1){
		perror("shmat failed");
		exit(1);
	}
	shared_data = (struct check_data *)shmaddr;

	while(1) {
		while(shared_data->check){
			sleep(1);
			printf("waiting... \n");
		}
		printf("input data ==>");
		fgets(buffer, SIZE, stdin);

		strncpy(shared_data->data, buffer, SIZE);
		shared_data->check =1;
		if(!strncmp(shared_data->data, "quit", 4)){
			break;
		}
	}
	if(shmdt(shmaddr) == -1){
		perror("shmdt failed");
		exit(1);
	}
	exit(0);
}
