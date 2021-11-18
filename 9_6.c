#include <stdio.h>
#include <stdlib.h>

int main(int argc, char**argv)
{
	char *pt;
	printf("%g\n", strtod("1.23", NULL));
	printf("%g\n", strtod("0.12E12", NULL));
	printf("%g ", strtod("\t-367.177abc", &pt));
	printf("%s\n",pt);
}

