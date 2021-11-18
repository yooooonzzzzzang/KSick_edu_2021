#include <stdio.h>
#include <stdlib.h>

int main(int argc, char**argv)
{
	char *pt;

	printf("%ld\n", strtol("3579", NULL,10));
	printf("%ld\n", strtol("3574", NULL, 8));
	printf("%ld\n", strtol("02521", NULL, 0));
	printf("%ld ", strtol("A2C@q", &pt , 16));
	printf("%s\n", pt);
}

