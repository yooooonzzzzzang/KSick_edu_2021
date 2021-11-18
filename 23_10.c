#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char**argv)
{
	int pid1, pid2, child_pid, status;
	if((pid1=fork()) ==-1)
		perror("fork failed");
	else if(pid1 !=0){
		if((pid2=fork()) ==-1)
			perror("fork fialed");
		else if(pid2 != 0){
			child_pid =waitpid(pid1, &status, 0);
			printf("child [pid:%d] terminated with code %x\n", child_pid, status);
		}else {
			printf("run child2[pid: %u]\n",getpid());
			exit(3);
		}
	}else{
		printf("run child1[pid:%u]\n",getpid());
		exit(2);
	}
}
