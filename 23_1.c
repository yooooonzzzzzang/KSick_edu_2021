#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc,char**argv)
{       
        printf("one\n");
        if(fork()==-1)
                perror("fork failed");
        else
                printf("two\n");
}       


