#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#define BUFFSIZE 1024 

int main(int argc, char**argv)
{
	int fd1, fd2;
	ssize_t n;
	char buf[BUFFSIZE];

	fd1=open("jkim", O_RDONLY);
	fd2=open("kang", O_WRONLY);
	n=read(fd1, buf, BUFFSIZE);
	write(fd2, buf, n);
	close(fd1);
	close(fd2);
}

