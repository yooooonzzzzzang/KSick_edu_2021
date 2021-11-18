#include <stdio.h>
#include <string.h>

int main(int argc, char**argv)
{
	char *str="ABCABCABCABCABCD";
	char *ptr;

	ptr=strrchr(str,'A');
	printf("%s\n", ptr);
}

