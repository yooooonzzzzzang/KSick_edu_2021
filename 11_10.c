#include <stdio.h>

int main(int argc, char**argv)
{
	FILE *fp;
	int ch = 'a';

	fp = fopen("source", "r");
	fputc(ch,fp);

	if(ferror(fp))
		puts("error");
	else
		puts("no error");

	clearerr(fp);
	if(ferror(fp))
		puts("errorr");
	else
		puts("no errorr");
	fclose(fp);
}
