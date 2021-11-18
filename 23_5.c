#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char**argv)
{
	pid_t pid;
	if((pid=fork()) ==-1){
		perror("fork failed");
		exit(1);
	}else if(pid !=0){
			printf("parent process\n");
			exit(2);
				 }else{
					 printf("child process\n");
					 exit(3);
				 }
		}
	
