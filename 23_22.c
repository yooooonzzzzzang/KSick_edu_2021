#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
char *envp[]={"User=jkim", "path=/tmp", (char*)0};
int main(int argc, char**argv)
{
	char *arg[] ={"23_21", (char *)0};

		printf("Running %s with execve\n", arg[0]);
		execve("./23_21", arg, envp);
		printf("execve failed to run %s\n", arg[0]);
		exit(0);
}
