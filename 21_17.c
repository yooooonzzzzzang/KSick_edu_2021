#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char**argv)
{
	int fd;

	if((fd=creat(argv[1], 0644))==-1){
		perror("creat failed");
		exit(1);
	}
	write(fd, "abcdefghijklmnopqrstuvwxyz" ,26);
	if(lseek(fd, 30, SEEK_SET)==-1){
		perror("lseek failed");
		exit(1);
	}
	write(fd, "ABCD", 4);
	close(fd);
	exit(0);
}

