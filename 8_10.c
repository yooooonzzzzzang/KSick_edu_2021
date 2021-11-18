#include <stdio.h>
#include <string.h>

int main(int argc, char**argv)
{
	char*str = "ABCDEFGH";
	char*ptr;
	ptr =strchr(str,'D');
	printf("%s\n", ptr);
}

