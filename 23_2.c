#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char**argv)
{
	pid_t pid;
	if((pid = fork()) ==-1)
		perror("fork faileD");
	else if(pid != 0)
		printf("parent process\n");
	else
		printf("child process\n");
}

