#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char**argv)
{
	for(i=0; i<125; i++)
		printf("[%3d] %s\n", i, strerror(i));
	exit(0);
}

