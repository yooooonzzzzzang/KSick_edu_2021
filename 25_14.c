#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#define SIZE 128
#define FIFO "fifo"
#include <stdlib.h>

int main(int argc, char **agrv)
{
	int fd, i;
	char buffer[SIZE];

	if((fd=open(FIFO, O_WRONLY)) == -1){
		perror("open failed");
		exit(1);
	}

	for(i=1; i<argc; i++){
		strcpy(buffer, argv[i]);
		if(write(fd, buffer, SIZE) ==-1){
			perror("write failed");

