#include <stdio.h>

void func(void);

int main(int argc, char**argv)
{
	int i;

	for(i=0; i<10; i++)
		func();
}

void func(void)
{
	int auto_var = 0;
	static int stat_var =0;

	printf("auto: %d static: %d\n", ++auto_var, ++stat_var);
}

