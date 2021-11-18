#include <stdio.h>
#include <stdlib.h>

int main(int argc, char**argv)
{
	int *ptr;
	int arr[5] ={1,2,3,4,5};
	int i;

	if((ptr=(int *)calloc(5,sizeof(int))) == NULL)
		exit(1);
	for(i=0; i<5; i++)
		ptr[i] = arr[i];

	if((ptr=(int *)realloc(ptr, sizeof(int)*10))==NULL)
		exit(1);
	for(i=5; i<10; i++)
		ptr[i]=arr[i-5];
	for(i=0; i<10; i++)
		printf("%d ", ptr[i]);
	printf("\n");

	free(ptr);
}

