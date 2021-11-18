#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char**argv)
{
	struct stat st1, st2;

	if(stat(argv[1], &st1)==-1){
		perror("stat failed");
		exit(1);
	}
	if(stat(argv[2], &st2)==-1){
		perror("stat failed");
		exit(1);
	}
	printf("%s is up-to-date file\n", (st1.st_mtime > st2.st_mtime) ? argv[1] : argv[2]);
	exit(0);
}

