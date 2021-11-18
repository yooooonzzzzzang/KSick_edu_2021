#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char**argv)
{
	if(link(argv[1], argv[2])== -1){
		perror("link failed");
		exit(1);
	}
	if(unlink(argv[1]) ==-1){
		perror("unlink failed");
		unlink(argv[2]);
		exit(1);
	}
	printf("move %s to %s\n", argv[1], argv[2]);
	exit(0);
}

