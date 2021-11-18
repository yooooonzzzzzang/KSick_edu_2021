#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#define MAX 1024

int main(int argc, char**argv)
{
	int count;
	char buf[MAX];

	while((count=read(STDIN_FILENO, buf, MAX)) >0){
		if(write(STDOUT_FILENO, buf, count) != count){
			perror("write failed");
			exit(1);
		}
	}
	exit(0);
}

