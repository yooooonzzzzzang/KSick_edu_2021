#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int main(int argc, char**argv)
{
	FILE *fp;
	fp = fopen("yesdata","r");
	assert(fp);
	printf("yesdata exit\n");
	fclose(fp);

	fp=fopen("nodata","r");
	assert(fp);
	printf("nodata exist\n");
	fclose(fp);

	exit(0);
}

