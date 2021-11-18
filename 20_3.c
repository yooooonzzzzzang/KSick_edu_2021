#include <stdio.h>
#include <stdlib.h>

int main(int argc, char**argv)
{
	int i;

	for(i=1; i<argc; i++)
	{
		if(argv[i][0] == '-')
			printf("option: %s\n", argv[i]+1);
		else
			printf("argument : %s\n", argv[i]);
	}
}

