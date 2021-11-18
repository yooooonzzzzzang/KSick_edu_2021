#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>

int find_file(char *dir, char*file);

int main(int argc, char**argv)
{
	if(find_file(argv[1], argv[2]))
		printf("found %s\n", argv[2]);
	else
		printf("not found %s\n",argv[2]);
	exit(0);
}
int find_file(char *dir, char *file)
{
	DIR *dp;
	struct dirent *dirp;
	if((dp=opendir(dir))==NULL){
		perror("opendir failed");
		exit(1);
	}
	while((dirp=readdir(dp))){
		if(!strcmp(dirp->d_name,file)){
			closedir(dp);
			return 1;
		}
	}
	closedir(dp);
	return 0;
}



