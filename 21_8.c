#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#define MAX 10

int main(int argc, char**argv)
{
	int fd;
	char buf1[MAX], buf2[MAX];
	if((fd =open("alphabet", O_RDONLY))==-1){
		perror("open failed");
		exit(1);
	}
	read(fd, buf1, MAX);
	read(fd, buf2, MAX);
	printf("buf1: %s\n buf2 : %s\n", buf1, buf2);
	close(fd);
	exit(0);
}

