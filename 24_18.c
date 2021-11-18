#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main(int argc, char**argv)
{
	sigset_t set1, set2;

	sigfillset(&set1);
	sigemptyset(&set2);
	sigaddset(&set2, SIGINT);
	sigprocmask(SIG_BLOCK, &set1, NULL);
	printf("block start\n");
	sleep(10);
	sigprocmask(SIG_UNBLOCK, &set2, NULL);
	printf("SIGINT unvlock\n");
	while(1) {
		printf("Hello WOrld\n");
		sleep(2);
	}
}

