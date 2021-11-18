#include <stdio.h>
#define MAX 128

int main(int argc, char**argv)
{
	char str[MAX];

	while(fgets(str, MAX, stdin)!= NULL){
		puts(str);
	}
}

