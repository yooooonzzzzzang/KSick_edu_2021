#include <stdio.h>
#include <stdlib.h>

int main(int argc, char**argv)
{
	char *value;

	if((value=getenv("HOME")) != NULL)
		printf("HOME : %s\n", value);
	else
		printf("HOME : no value\n");
	unsetenv("HOME");

	if((value=getenv("HOME")) != NULL)
		printf("HOME : %s\n", value);
	else
		printf("HOME : no value\n");

	exit(0);

}

