#include <stdio.h>
int main(int argc, char**argv)
{
	int ch ='Z';
	do{
		printf("%c", ch--);
	}while(ch>='A');
	printf("\n");
}

