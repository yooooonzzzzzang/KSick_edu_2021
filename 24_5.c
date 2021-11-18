#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main(int argc, char**argv)
{
     int count = 0;

     signal (SIGINT, SIG_IGN);
     while(1) {
	     printf("Hello World\n");
	     sleep(1);
	     if (++count ==5)	 
		     signal(SIGINT, SIG_DFL);
     }
}

