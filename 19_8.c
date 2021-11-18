#include <stdio.h>
#include <stdlib.h>

void my_assert(int expression);

int main(int argc, char**argv)
{
	my_assert(7==7);
	printf("yes\n");

	my_assert(3==5);
	printf("no\n");
}
void my_assert(int expression)
{
	if(!(expression)){
		printf("%s: %d: Assertion failed\n", __FILE__, __LINE__);
	abort();
	}
}

