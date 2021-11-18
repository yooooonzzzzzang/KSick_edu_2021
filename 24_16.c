#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define MAX 100

int main(int argc, char**argv)
{
	char buffer[MAX];
	int n;
	
	alarm(10);	
	n=read(0, buffer, MAX);
       alarm(0);
	write(1, buffer, n);
 	exit(0);
}

