#include <stdio.h>
#include <stdlib.h>

int main(int argch, char**argv)
{
	if(rename(argv[1], argv[2]) == -1){
		perror("rename failed");
		exit(1);
	}
	printf("rename %s to %s\n", argv[1], argv[2]);
	exit(0);
}

