#include <stdio.h>
#include <stdlib.h>

int main(int argc, char**argv)
{
	char *home_dir, *work_dir, *tmp;
	if((home_dir=getenv("HOME")) != NULL)
		printf("home directory : %s\n", home_dir);
	if((work_dir = getenv("PWD")) != NULL)
		printf("working directory : %s\n", work_dir);

	if((tmp = getenv("Linux")) != NULL )
		printf("temp : %s\n", tmp);
}

