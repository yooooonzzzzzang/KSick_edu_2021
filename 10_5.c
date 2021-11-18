#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char**argv)
{
	int *ptr;

	if((ptr=(int *)malloc(10))==NULL)
		exit(1);
	memset(ptr, 'a', 9);
	ptr[9];

	printf("%s\n", ptr);
	free(ptr);
}

