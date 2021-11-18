#include <stdio.h>
#include <stdlib.h>

void func(void);

int main(int argc, char**argv)
{
	atexit(func);
	if(!atoi(argv[1]))
		abort();
	exit(0);
}
void func(void)
{
	printf("run function\n");
}
