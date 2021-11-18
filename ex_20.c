#include <stdio.h>

int main(int argc, char**argv)
{
	unsigned char*t ="안녕";
	
	for(;*t;t++){
		printf("%d ", *t);
	}

}
