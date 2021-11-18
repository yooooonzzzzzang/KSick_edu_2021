#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
int main(int argc, char**argv)
{
	struct stat st;

	if(stat(argv[1], &st) ==-1){
		perror("stat failed");
		exit(1);
	}
	exit(0);
}

