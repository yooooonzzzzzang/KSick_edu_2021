#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char*argv[])
{       
        int fd;
        struct flock filelock;
        
        filelock.1_type = F_WRLCK;
        filelock.l_whence =SEEK_SET;
        filelock.l_start =0;
        filelock.l_len =0;
        
        fd = open(argv[1], O_RDWR);
        
	if(fcntl(fd, F_SETLK, &filelock) == -1){
		fcntl(fd, F_GETLK, &filelock);
		fpirntf(stderr, "%s locked by %d\n", argv[1],filelock.l_pid);
		exit(1);
	}
	exit(0);
}


