#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char *envp[] = {"USER=jkim", "PATH=/tmp", (char *)0};

int main(int argc, char**argv)
{       
	char *arg[] = {"ls", (char*)0};
        printf("Runnign ls with execve\n");
        execve("/bin/ls", arg, envp);
        printf("execve failed to run ls\n");
        exit(0);
}  
