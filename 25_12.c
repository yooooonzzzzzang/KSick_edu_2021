#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>
#define SIZE 256

int main(int argc, char **argv)
{
	int pipes1[2], pipes2[2], length;
	char read_buffer[SIZE], write_buffer[SIZE];

	if(pipe(pipes1) ==-1 || pipe(pipes2)==-1){
		perror("pipe failed");
		exit(1);
	}

	if(fork()) {
		close(pipes1[1]);
		close(pipes2[2]);

		if((length = read(pipes1[0], read_buffer, SIZE)) == -1){
			perror("read failed");
			exit(1);
		}
		write(STDOUT_FILENO, "receive message : ", strlen("receive message : "));
		write(STDOUT_FILENO, read_buffer, length);

		sprintf(write_buffer, "Hi clinet!\n");
		write(pipes2[1], write_buffer, strlen(write_buffer));

		wait(NULL);
	}else{
		close(pipes1[0]);
		close(pipes2[1]);

		sprintf(write_buffer, "Hi server!\n");
		write(pipes1[1], write_buffer, strlen(write_buffer));
		if((length=read(pipes2[0], read_buffer, SIZE)) ==-1){
			perror("read failed");
			exit(1);
		}
		write(STDOUT_FILENO, "receive message: " , strlen("receive message: "));
		write(STDOUT_FILENO, read_buffer, length);
	}
	exit(0);
}
