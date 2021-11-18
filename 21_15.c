#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#define MAX 1024

int main(int argc, char**argv)
{
	int fd1, fd2;
	int count;
	char buf[MAX];

	if(argc != 3){
		perror("argc is not 3");
		exit(1);
	}
	if((fd1=open(argv[1], O_RDONLY)) == -1){
			perror("open failed");
			exit(1);
	}
	if((fd2=creat(argv[2], 0644))==-1){
		perror("creat failed");
		exit(1);
	}
	while((count=read(fd1, buf, MAX)) >0){
		if(write(fd2,buf, count)!=count){
			perror("write failed");
			exit(1);
		}
	}
	close(fd1);
	close(fd2);
	exit(0);
}

