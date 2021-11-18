#include <stdio.h>
#include <signal.h>
#include <unistd.h>


void signalHandler(int signo);
int signal_count = 0;


int main(int argc, char**argv)
{
	struct sigaction new_act;
	struct sigaction old_act;

	new_act.sa_handler = signalHandler;

	sigemptyset(&new_act.sa_mask);
	new_act.sa_flags=0;
	sigaction(SIGINT, &new_act, &old_act);

	while(1){
		printf("waiting signal\n");
		sleep(1);
		if (signal_count ==3)
		       sigaction(SIGINT, &old_act, NULL);
	}
}

void signalHandler(int signo)
{
	signal_count++;
	printf("HI! singal %d\n", signal_count);
}

