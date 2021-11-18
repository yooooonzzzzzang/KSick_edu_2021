#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void signalHandler(int signo);
int main(int argc, char** argv)
{
	sigset_t set, oldset;
	struct sigaction act;

	act.sa_handler = signalHandler;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
       sigaction(SIGINT, &act, NULL);

	sigemptyset(&set);
 	sigaddset(&set,SIGINT);

	sigprocmask(SIG_BLOCK, &set, &oldset);
	sleep(10);
	sigprocmask(SIG_SETMASK, &oldset, NULL);
	pause();
	exit(0);
}
void signalHandler(int signo)
{
	printf("Hi! signal %d\n", signo);
}

