#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char**argv)
{
	int status;
	if(fork()) {
		wait(&status);
		printf("child process terminated with code %x\n", status);
	}else {
		alarm(3);
		printf("looping forever ... \n");
		while(1)
			;
	}
}
