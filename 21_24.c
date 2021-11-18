#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char**argv)
{
	int fd;

	if((fd = open(argv[1], O_WRONLY)) == -1){
		perror("open failed");
		exit(1);
	}
	if((dup2(fd,7)) ==-1){
		perror("dup2 failed");
		exit(1);
	}
	if(lseek(7,0, SEEK_END) == -1){
		perror("lseek failed");
		exit(1);
	}
	write(7, " ABCD", 5);
	close(fd);
	exit(0);
}

