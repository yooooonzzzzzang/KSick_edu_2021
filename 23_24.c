#include <stdio.h>
#include <stdlib.h>
int main(int argc, char**argv)
{
	printf("Running ls with system\n");
	system("ls");
	printf("Done\n");
	exit(0);
}

