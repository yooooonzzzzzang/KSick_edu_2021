#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#define SIZE 1024
#include <signal.h>

int main(int argc, char**argv)
{
	int shmid;
	void *shmaddr;
	struct shmid_ds shm_stat;

	if((shmid=shmget((key_t)1234, SIZE,IPC_CREAT|0666)) == -1){
		perror("shmid failed");
		exit(1);
	}

	if((shmaddr=shmat(shmid, (void *)0,0 )) == (void *)-1){
		perror("shmat failed");
		exit(1);
	}
	printf("data read from shared memory : %s\n", (char *)shmaddr);
	
	if(shmctl(shmid, IPC_STAT, &shm_stat) == -1){
		perror("shmctl failed");
		exit(1);
	}

	if(shmdt(shmaddr) == -1){
		perror("shmdt failed");
			exit(1);
	}
	kill(shm_stat.shm_cpid,SIGINT);
		exit(0);
}

