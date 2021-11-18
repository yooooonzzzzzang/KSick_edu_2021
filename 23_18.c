#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char**argv)
{       
        char *arg[] ={"ls", (char *)0};
	printf("Runnign ls with execvp\n");
        execvp("ls",arg);
        printf("execvp failed to run ls\n");
        exit(0);
}  
