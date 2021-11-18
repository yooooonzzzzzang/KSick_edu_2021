#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc,char **argv)
{
	if(mkdir("dir", 0755)==-1){
		perror("mkdir failed");
		exit(1);
	}
	if(mkdir("dir") == -1){
		perror("rmdir failed");
		exit(2);
	}
	exit(0);
}

