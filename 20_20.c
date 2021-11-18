#include <stdio.h>
#include <grp.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
	gid_t gid;
	struct group *pg;
	

	gid= getgid();
	pg=getgrgid(gid);
	printf("group name: %s\n", pg->gr_name);
	exit(0);
}

