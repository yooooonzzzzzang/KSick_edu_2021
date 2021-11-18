#include <stdio.h>
#include <math.h>

int main(int argc, char**argv)
{
	double fra, itr;
	printf("%g\n", ceil(123.45));
	printf("%g\n", floor(345.67));

	fra =modf(123.45 ,&itr);
	printf("%g, %g\n", itr, fra);
}

