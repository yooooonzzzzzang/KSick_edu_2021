#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char**argv)
{
	printf("Running is with execl\n");
	execl("/bin/ls", "ls", (char *)0);
	printf("execl failed to run ls\n");
	exit(0);
}

