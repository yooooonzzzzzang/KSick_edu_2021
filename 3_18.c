#include <stdio.h>
int main(int argc, char**argv)
{
	int ch='Z';

	while(ch>='A')
		printf("%c", ch--);
	printf("\n");
}

