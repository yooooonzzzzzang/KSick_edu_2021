#include <stdio.h>
#include <ctype.h>


int main(int argc, char**argv)
{
	int ch;

	while((ch =getchar())!=EOF){
		if(islower(ch))
			ch = toupper(ch);
		else if(isupper(ch))
			ch=tolower(ch);
		putchar(ch);
	}
	putchar('\n');
}

