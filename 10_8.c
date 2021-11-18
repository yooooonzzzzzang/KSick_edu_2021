#include <stdio.h>
#include <string.h>

int main(int argc, char**argv)
{
	char *string ="ABCDEABCDEABCDE";
	while(1) {
		if((string =memchr(string,'A',strlen(string)))==NULL)
			break;
		printf("%s\n", string);
		string++;
	}
}

