#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void alarmHandler(int signo);

int main(int argc, char**argv)
{
	int status;
	struct sigaction act;

	act.sa_handler = alarmHandler;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	sigaction(SIGALRM,&act, NULL);
	alarm(3);
	while(1)	
		;
}

void alarmHandler(int signo)
{
	printf("Hi! signal %d\n", signo);
	exit(0);
}

