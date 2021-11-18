#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc, char**argv)
{
	sigset_t set,pend;

	sigfillset(&set);
	sigprocmask(SIG_BLOCK, &set, NULL);
	while(1) {
		printf("Hello World\n");
		sleep(2);
		sigpending(&pend);
		if(sigismember(&pend, SIGQUIT))
			exit(0);
	}
}

