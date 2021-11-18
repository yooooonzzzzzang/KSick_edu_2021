#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
int main(int argc,char**argv)
{
	DIR *dp;

	if(mkdir("dir", 0755) == -1){
		perror("mddir failed");
		exit(1);
	}
	if((dp=opendir("dir")) ==NULL){
		perror("opendir failed");
		exit(1);
	}
	closedir(dp);
	exit(0);
}

