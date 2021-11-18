#include <stdio.h>
int main(int argc, char**argv)
{
	int i;
	short j;
	long k;
	unsigned l;

	printf("int %ld %ld\n", sizeof(int), sizeof(i));
	printf("short %ld %ld\n", sizeof(short), sizeof(j));
	printf("long %ld %ld\n", sizeof(long), sizeof(k));
	printf("unsigned %ld %ld\n", sizeof(unsigned), sizeof(l));
}

