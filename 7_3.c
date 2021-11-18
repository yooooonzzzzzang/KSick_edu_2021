#include <stdio.h>
#define SIZE 1000

int main(int argc, char**argv)
{
	int num;
	num = SIZE;
	printf("%d\n", num);

#undef SIZE
#define SIZE 5000
	num = SIZE;
	printf("%d\n", num);
}

