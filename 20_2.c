#include <stdio.h>
#include <stdlib.h>

int max(int num1, int num2);
int main(int argc, char**argv)
{
	if(argc != 3){
		printf("Usage : a.out number1 number2\n");
		exit(1);
	}
	printf("max number: %d\n", max(atoi(argv[1]), atoi(argv[2])));
	exit(0);
}
int max(int num1, int num2)
{
	if(num1> num2)
		return num1;
	else
		return num2;
}

