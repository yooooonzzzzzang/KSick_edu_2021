#include <stdio.h>
#include <math.h>
#include <errno.h>
#include <stdlib.h>
int main(int argc, char**argv)
{
	double y;
	errno =0;
	y =sqrt(-1);

	if(errno != 0){
		printf("errno = %d\n", errno);
		exit(1);
	}
	
	exit(0);
}

