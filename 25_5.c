#include <stdio.h>
#include <unistd.h>
#define SIZE 20
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
int main(int argc, char**argv)
{
	int fd;
	struct flock filelock;
	char buffer[SIZE];
	int length;

	filelock.l_type = F_RDLCK;
	filelock.l_whence = SEEK_SET;
	filelock.l_start = 0;
	filelock.l_len =0;

	fd = open(argv[1], O_RDWR);
	if(fcntl(fd, F_SETLKW, &filelock) == -1){
		perror("fcntl failed");
		exit(1);
	}
	printf("locked %s\n", argv[1]);
	length = read(fd, buffer, SIZE);
	write(STDOUT_FILENO, buffer, length);
	printf("unlocked %s\n", argv[1]);
	exit(0);
}

