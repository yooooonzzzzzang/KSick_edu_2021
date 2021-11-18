#include <stdio.h>
int main(int argc, char**argv)
{
	char *str;
	str="Hello";
	for(; *str; str++)
		printf("%s\n", str);
}

