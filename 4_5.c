#include <stdio.h>

int main(int argc, char**argv)
{
	int arr[5] ={10,20,30,40,50};
	int *ptr;
	int i;

	for (ptr=arr, i=0; i<5; i++)
		printf("%d\n", *ptr++);
}

