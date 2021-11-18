#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
int main(int argc, char**argv)
{
	int fd1, fd2;
	fd1 = open("jkim", O_RDONLY);
	fd2 = open("kang", O_WRONLY);
	printf("jkim's file descriptor: %d\n kang's file descriptor: %d\n",fd1, fd2);
	close(fd1);
	close(fd2);
}

