#include <stdio.h>
int main(int argc, char**argv)
{
	int i;
	for(i=1; i<=30; i++){
		if(i%5)
			continue;
		printf("%d ", i);
	}
	printf("\n");
}

