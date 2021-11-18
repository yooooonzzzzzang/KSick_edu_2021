#include <stdio.h>
#include <string.h>
#define MAX 20

int main(int argc, char**argv)
{
	char str[MAX];
	int i, j, ch;

	printf("Input string ==> ");
	scanf("%s", str);

	for(i=0, j=strlen(str)-1; i<j; i++, j--){
		ch =str[i];
		str[i] =str[j];
		str[j] =ch;
	}
	printf("reverse : %s\n", str);
}

