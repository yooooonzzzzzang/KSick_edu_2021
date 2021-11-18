#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char**argv)
{
	int *ptr;
	int arr[5] ={1,2,3,4,5};
	int i;

	if((ptr=(int *)calloc(5,sizeof(int))) == NULL)
		exit(1);

	memcpy(ptr, arr, 5*sizeof(int));
	for(i=0; i<5; i++)
		printf("%d ", ptr[i]);
	printf("\n");
}

