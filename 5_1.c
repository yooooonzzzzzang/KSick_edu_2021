#include <stdio.h>

void swap_val(int x, int y);
void swap_addr(int *x, int*y);

int main(int argc, char**argv)
{
	int a=7, b=11;

	swap_val(a,b);
	printf("%d %d\n", a,b);

	swap_addr(&a,&b);
	printf("%d %d\n",a,b);
}
void swap_val(int x, int y)
{
	int temp;
	temp =x;
	x=y;
	y=temp;
}
void swap_addr(int *x, int *y)
{
	int temp;
	temp = *x;
	*x= *y;
	*y =temp;
}

