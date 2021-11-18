#include <stdio.h>
#include <stdlib.h>

void func1(void);
void func2(void);
void func3(void);

int main(int argc, char**argv)
{
	atexit(func1);
	atexit(func2);
	atexit(func3);

	exit(0);
}
void func1(void)
{
	printf("run function1");
}
void func2(void)
{
	printf("run function2");
}
void func3(void)
{
	printf("run function3");
}
