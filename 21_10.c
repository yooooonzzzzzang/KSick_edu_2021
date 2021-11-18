#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char**argv)
{
	int fd;
	char buf[20] = "Linux C Programming";

	if((fd=open("newfile", O_WRONLY|O_CREAT, 0644))==-1){
		perror("open failed");
		exit(1);
	}
	if(write(fd, buf, 20) ==-1){
		perror("write failed");
		exit(1);
	}
	close(fd);
	exit(0);
}

