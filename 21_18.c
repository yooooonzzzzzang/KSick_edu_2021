#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char**argv)
{
	int fd;
	off_t filesize;

	if((fd = open(argv[1], O_RDONLY)) ==-1){
		perror("open failed");
		exit(1);
	}
	printf("%s\'s size is %ld\n", argv[1], filesize);
	close(fd);
	exit(0);
}

