#include <stdio.h>
#include <stdlib.h>
int main(int argc, char**argv)
{
	int i;
	int k=atoi(argv[1]);

	for(i=1; i<10; i++)
		printf("%d x %d = %d\n", k, i, k*i);

	exit(0);
}

