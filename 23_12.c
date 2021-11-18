#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char**argv)
{
	int pid, status;
	if((pid=fork()) ==-1)
		perror("fork failed");
	else if(pid != 0){
		while (waitpid(pid, &status, WNOHANG )== 0){
			printf("still waiting\n");
			sleep(1);
		}
	}else{
		printf("run child\n");
		sleep(5);
		exit(0);
	}
}
