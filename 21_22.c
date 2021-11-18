#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char**argv)
{
	int fd;
	if((fd=dup(1)) == -1){
		perror("dup failed");
		exit(1);
	}
	write(fd, "ABCD", 5);
	exit(0);
}

