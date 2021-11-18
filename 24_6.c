#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void signalHandler(int signo);

int main(int argc, char**argv)
{
       signal(SIGINT, signalHandler);
	while(1){
	 printf("Hello World \n");
 	sleep(1);
	}
}
void signalHandler(int signo)
{
	printf("Hi! signal %d\n", signo);
	signal(SIGINT, SIG_DFL);
}

