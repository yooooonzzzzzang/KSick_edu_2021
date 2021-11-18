#include <stdio.h>

int main(int argc, char**argv)
{
	int ch;
	printf("Input character ==> ");
	ch =getchar();

	if((ch>='a'&& ch<='z')||(ch>='A'&&ch<='Z'))
		printf("alphabet character\n");
	else if (ch>='0' &&ch<='9')
		printf("numeric character\n");
	else
		printf("others\n");
}

