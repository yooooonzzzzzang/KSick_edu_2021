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
	struct shmid_ds shm_stat;

	if((shmid =shmget((key_t)1234, sizeof(struct check_data),IPC_CREAT|0666)) == -1){
		perror("shmid failed");
		exit(1);
	}
	if((shmaddr=shmat(shmid, (void *)0,0)) ==(void *)-1){
		perror("shmat failed");
		exit(1);
	}
	shared_data = (struct check_data *)shmaddr;
	shared_data->check =0;

	while(1){
		if(shared_data->check){
			printf("data read from shared memory : %s", shared_data->data);
			sleep(1);
			shared_data->check =0;
			if(!strncmp(shared_data->data, "quit", 4)){
				if(shmctl(shmid, IPC_STAT, &shm_stat) == -1){
					perror("shmctl failed");
					exit(1);
				}
				if(shm_stat.shm_nattch ==1)
					break;
			}
		}
		sleep(1);
	}
	if(shmdt(shmaddr) == -1){
		perror("shmdt failed");
		exit(1);
	}
	if(shmctl(shmid, IPC_RMID,0) ==-1){
		perror("shmctl failed");
		exit(1);
	}
	exit(0);
}

