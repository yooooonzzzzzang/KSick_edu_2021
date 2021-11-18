#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char**argv)
{	

	char *quit ="quit";
	char *string =malloc(sizeof(string));
	
	while(1){
		printf("Input string ==> ");
		scanf("%s", string);
		if(!memcmp(string, quit, 4))
			break;
		printf("%s\n", string);
	}
}

	
