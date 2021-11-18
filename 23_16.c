#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char *envp[]={"USER=jkim", "PATH=/tmp", (char *)0};

int main(int argc, char**argv)
{       
        printf("Runnign ls with execle\n");
        execle("/bin/ls", "ls", (char *)0, envp);
        printf("execle failed to run ls\n");
        exit(0);
}  
