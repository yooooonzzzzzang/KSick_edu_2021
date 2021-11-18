#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	int fd, newfd;

	if((fd = open(argv[1], O_WRONLY)) == -1){
		perror("open failed");
		exit(1);
	}
	if((newfd=dup(fd)) ==-1){
		perror("dup failed");
		exit(1);
	}
	if(lseek(newfd, 0, SEEK_END) == -1){
		perror("lseek failed");
		exit(1);
	}
	write(newfd, " ABCD", 5);
	close(fd);
	exit(0);
}

