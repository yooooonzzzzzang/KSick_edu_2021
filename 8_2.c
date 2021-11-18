#include <stdio.h>
#include <ctype.h>

int main(int argc, char**argv)
{
	int ch;
	while((ch=getchar()) != EOF){
		if(isalpha(ch))
			putchar(ch);
	}
	putchar('\n');
}
