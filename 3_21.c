#include <stdio.h>

int main(int argc, char**argv)
{
	int ch;
	while ((ch=getchar()) != EOF){
		if(ch == '\n'){
			break;
		}
		putchar(ch);
	}
	putchar('\n');
}

