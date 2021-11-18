#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
int main(int argc, char**argv)
{
        int fd;
        struct flock filelock;

        filelock.l_type = F_WRLCK;
        filelock.l_whence =SEEK_SET;
        filelock.l_start = 0;
        filelock.l_len = 0;

        fd = open(argv[1], O_RDWR | O_CREAT, 0666);

        if(fcntl(fd, F_SETLK, &filelock) == -1){
        perror("fcntl failed");
        exit(1);
        }
        printf("locked %s\n", argv[1]);
        write(fd, "Hi Linux", 9);
	sleep(5);
	printf("unlocked %s\n",argv[1]);
	exit(0);
}


