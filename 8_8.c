#include <stdio.h>
#include <string.h>

int main(int argc, char**argv)
{
	char *ptrstr;
	ptrstr = strdup("Hello Linux");
	printf("%s\n", ptrstr);
}

