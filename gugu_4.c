#include <stdio.h>
#include <stdlib.h>
int main(int argc, char**argv)
{
	int i;
	int j;

	
	for(j=1; j<argc; j++)
	{

		for(i=1; i<10; i++){
			printf("%d x %d = %d\n", atoi(argv[j]), i,atoi(argv[j])*i);
		}
		printf("\n");
	}
	
}


