#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char**argv)
{
	int fd;

	if(mkdir(argv[1], 0755) ==-1){
		perror("mkdir failed");
		exit(1);
	}
	if(chdir(argv[1]) ==-1){
		perror("chdri failed");
		exit(1);
	}
	if((fd=open(argv[2], O_WRONLY|O_CREAT, 0644))==-1){
		perror("open failed");
		exit(1);
	}
	write(fd, argv[3], strlen(argv[3]));
	close(fd);
	exit(0);
}

