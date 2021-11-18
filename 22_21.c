#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>

int main(int argc, char**argv)
{
	if(chmod("jkim", 0644) == -1)
		perror("chmode failed");
	if(chmod("kang", S_IRUSR |S_IWUSR|S_IRGRP|S_IROTH)== -1)
		perror("chmod failed");
	exit(0);
}

