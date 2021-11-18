#include <stdio.h>
int main(int argc, char**argv)
{
	int i;
	printf("Input integer ==> ");
	scanf("%d", &i);
	switch(i){
		case 1:
			printf("Hello 1\n");
		case 2:
			printf("Hello 2\n");
		case 3:
			printf("Hello 3\n");
		default:
			printf("Hello others\n");
	}
}

