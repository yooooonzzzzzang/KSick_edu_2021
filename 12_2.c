#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char**argv)
{
	div_t result1;
	ldiv_t result2;
	result1 =div(12345, 2345);
	result2 = ldiv(123456789,12345678);

	printf("%d, %d\n", result1.quot, result1.rem);
	printf("%ld, %ld\n", result2.quot, result2.rem);
	printf("%g\n", fmod(23.456,2.345));
}

		
