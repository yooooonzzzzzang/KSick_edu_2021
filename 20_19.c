#include <stdio.h>
#include <grp.h>
#include <sys/types.h>
#include <stdlib.h>
int main(int argc,char **argv)
{
	struct group *pg;
	int i;

	while((pg= getgrent())){
		printf("goup name : %s\n member : ", pg->gr_name);
		for(i=0; pg->gr_mem[i]!=NULL; i++)
			printf("%s ", pg->gr_mem[i]);
		printf("\n\n");
	}
	endgrent();
	exit(0);
}

