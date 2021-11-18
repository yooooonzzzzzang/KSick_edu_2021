#include <stdio.h>
#include <stdlib.h>
int main(int argc, char**argv)
{
	FILE *fp;
	int i;
	float j;
	char *str=malloc(sizeof(stdin));
	fp = fopen("data", "w");
	fprintf(fp, "%d %g %s\n", 123,12.345, "Hello");
	fclose(fp);
	fp= fopen("data","r");
	fscanf(fp, "%d%g%s", &i,&j, str);
	printf("%d %g %s\n",i,j,str);
	fclose(fp);
}

