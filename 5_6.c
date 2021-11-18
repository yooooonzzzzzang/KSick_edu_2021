#include <stdio.h>

void func(void);

static int count=0;

int main(int argc, char**argv)
{
	int i;

	for(i=0; i<10; i++)
		func();
	printf("count : %d\n", count);
}

