#include <stdio.h>
int main(int argc, char**argv)
{
	float arr[3];
	int i;

	for(i=0; i<3; i++)
		printf("arr[%d]: %lu ", i, (long unsigned int)&arr[i]);
	printf("\n");
}
