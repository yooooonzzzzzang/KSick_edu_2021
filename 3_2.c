#include <stdio.h>
int main(int argc, char**argv)
{
	int a, b;
	int c =2;
	int d=2;
	a=++c;
	b=d++;
	printf("a:%d b:%d c:%d d:%d\n", a, b, c, d);
}

