#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#define MAX 100

int main(int argc, char**argv)
{
	int fd, i;
	char buf[MAX];
	long int length =0;
	if((fd=open("jkim", O_RDONLY)) ==-1){
		perror("open failed");
		exit(1);
	}
	while((i=read(fd, buf, MAX)) >0)
		length += i;
	printf("Total characters in jkim : %ld\n", length);
	close(fd);
	exit(0);
}

