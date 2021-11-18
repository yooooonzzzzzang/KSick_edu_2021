#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
int main(int argc, char**argv)
{
	
	sigset_t set;

	
        if(sigemptyset(&set) == -1) {
       		perror("sigemptyset failed");
 		exit(1);
	}
if(sigaddset(&set, SIGINT) == -1){
	perror("sigaddest failed");
	exit(1);
}
if(sigismember(&set, SIGINT))
	printf("SIGINT is a member\n");
else
	printf("SIGINT is not a member\n");
exit(0);
	}

