#include <stdio.h>
#include <string.h>

int main(int argc, char**argv)
{
	char alphabet[] ="ABCDEFGHIJK";
	memmove(alphabet,alphabet+3, 2);
	printf("%s\n", alphabet);
}

