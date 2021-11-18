#include <stdio.h>
#define FNAME "jkim.txt"
int main(int argc, char**argv)
{
	FILE *fp;
	fp=fopen(FNAME,"r");

	if(fp)
	{
		printf("성공\n");
		fclose(fp);
	}
	else
	{
		printf("실패\n");
	}
}

