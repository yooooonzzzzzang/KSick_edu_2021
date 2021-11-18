#include <stdio.h>
#include <unistd.h>
#define SIZE 4
#include <stdlib.h>

int main(int argc,char**argv)
{
	char *arg[3] ={"abc" , "def", "ghi"};
	char buffer[SIZE];
	int pipes[2], i;

	if(pipe(pipes) == -1){
		perror("pipe failed");
		exit(1);
	}

	if(fork()){
		for(i=0; i<3; i++){
			write(pipes[1], arg[i], SIZE);
			printf("parent process write to pipe: %s\n", arg[i]);
		}
	}else{
		for(i=0; i<3; i++){
			read(pipes[0], buffer, SIZE);
			printf("child process read from pipe: %s\n", buffer);
		}
	}
	exit(0);
}

