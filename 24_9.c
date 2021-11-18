#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void signalHandler(int signo);


int main(int argc, char**argv)
{
	struct sigaction act;
	act.sa_flags = SA_NOMASK;
        sigaction(SIGINT, &act, NULL);
	printf("call sigaction\n");
	while(1)
		sleep(5);
}

void signalHandler(int signo)
{
	 printf("start handler\n");
	 sleep(3);
	 printf("end handler\n");
}

