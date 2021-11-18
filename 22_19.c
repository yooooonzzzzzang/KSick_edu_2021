#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char**argv)
{
	if(remove(argv[1])== -1){
			perror("remove failed");
			exit(1);
	}
	printf("remove %s\n", argv[1]);
	exit(0);
}

