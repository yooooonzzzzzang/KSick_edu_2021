#include <stdio.h>
#include <stdlib.h>

extern char **environ;

int main(int argc, char**argv)
{
	char **env = environ;
	printf("my environment variables are :\n");
	while(*env)
		printf("%s\n", *(env++));
	exit(0);
}



