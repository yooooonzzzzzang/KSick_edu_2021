#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char**argv)
{
	printf("%d\n", FOPEN_MAX);
	exit(0);
	}
