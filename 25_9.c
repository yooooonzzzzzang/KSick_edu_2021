#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define SIZE 4

int main(int argc, char**argv)
{
	char *arg[3] = {"abc", "def", "ghi"};
	char buffer[SIZE];
	int pipes[2],i;

	if(pipe(pipes) == -1){
		perror("pipe failed");
		exit(1);
	}

	for(i=0; i<3; i++){
		write(pipes[1], arg[i], SIZE);
	}
	for(i=0; i<3; i++){
		read(pipes[0], buffer, SIZE);
		printf("%s\n", buffer);
	}
	exit(0);
}

