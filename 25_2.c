#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int fd;
	struct flock filelock;

	filelock.l_type = (!strcmp(argv[2],"r")) ? F_RDLCK:F_WRLCK;
	filelock.l_whence = SEEK_SET;
	filelock.l_start = 0;
	filelock.l_len =0;

	fd=open(argv[2], O_RDWR);	
	if(fcntl(fd, F_SETLK, &filelock)==-1){
		perror("fcntl failed");
		exit(1);
	}
}
