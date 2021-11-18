#include <stdio.h>
#include <stdlib.h>

int main(int argc, char**argv)
{
	int *ptr;
	int arr[5] = {1,2,3,4,5};
	int i;

	if((ptr=(int *)calloc(5, sizeof(int))) ==NULL)
		exit(1);
	for(i=0;i<4;i++)
		ptr[i] = arr[i];
	for(i=0; i<5; i++)
		printf("%d",ptr[i]);
	printf("\n");
}

