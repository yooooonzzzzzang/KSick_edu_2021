#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	int fd;
	if((fd=open(argv[1], O_WRONLY)) ==-1){
		perror("open failed");
		exit(1);
	}
	if(ftruncate(fd,100) ==-1){
		perror("ftruncate failed");
		exit(1);
	}
	close(fd);
	exit(0);
}

