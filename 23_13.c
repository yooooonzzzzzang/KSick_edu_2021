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
		pid = wait(&status);
		if(WIFEXITED(status))
			printf("child terminated with code %d\n", WEXITSTATUS(status));
		else
			printf("child terminated abnormally\n");
	}else{
		printf("run child\n");
		exit(27);
	}
}

