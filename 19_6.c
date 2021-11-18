#include <stdio.h>
#include <stdlib.h>
#define NDEBUG
#include <assert.h>

int main(int argc, char**argv)
{
	FILE *fp;

	fp=fopen("yesdata", "r");
	assert(fp);
	printf("yesdata exist\n");
	fclose(fp);

	fp=fopen("nodata", "r");
	assert(fp);
	printf("nodata exist\n");
	fclose(fp);
	exit(0);
}

