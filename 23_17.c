#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char**argv)
{       
	char *arg[]={"ls", (char *)0};
        printf("Runnign ls with execv\n");
        execv("/bin/ls", arg);
        printf("execv failed to run ls\n");
        exit(0);
}  
