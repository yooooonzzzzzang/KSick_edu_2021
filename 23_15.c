#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char**argv)
{
	printf("Runnign ls with execlp\n");
	execlp("ls", "ls", (char *)0);
	printf("execlp failed to run ls\n");
	exit(0);
}

