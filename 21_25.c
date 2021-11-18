#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int filestatus(int fd, char*file);

int main(int argc, char**argv)
{
	int fd,newfd, mode;

	mode =atoi(argv[2]);
	if((fd = open(argv[1], mode)) == -1){
		perror("open failed");
		exit(1);
	}
	if(filestatus(fd, argv[1]) == -1){
		exit(2);
	}
	close(fd);
	exit(0);
}
int filestatus(int fd, char*file)
{
	int flag;

	if((flag=fcntl(fd, F_GETFL)) == -1){
		perror("fcntl failed");
		return -1;
	}
	switch (flag & O_ACCMODE){
		case O_RDONLY:  /*0*/
			printf("%s is read only file\n", file);
			break;
		case O_WRONLY:  /*1*/
			printf("%s is write only file\n", file);
			break;
		case O_RDWR:	/*2*/
			printf("%s is read-write file\n", file);
			break;
		default:
			printf("no such mode\n");
	}
	return 0;
}
