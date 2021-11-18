#include <stdio.h>
#include <stdlib.h>
int main(int argc, char**argv)
{
	int i;
	int j;

	for(i=1; i<10; i++)
	{
		for(j=1; j<argc; j++){
			printf("%d X %d = %d\t", atoi(argv[j]),i,atoi(argv[j])*i);
		}
				printf("\n");
		
		}
}

