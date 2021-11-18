#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int main(int argc, char**argv)
{
	int fd;
	char buf[MAX] ="C Program";

	if((fd=open("jkim", O_WRONLY|O_CREAT|O_APPEND,0644)) ==-1){
		perror("open failed");
		exit(1);
	}
	write(fd, buf, MAX);
	close(fd);
	exit(0);
}

