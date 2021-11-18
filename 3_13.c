#include <stdio.h>

int main(int argc, char**argv)
{
	char ch;
	printf("Input character ==>");
	scanf("%c", &ch);
	if((ch>='a')&&(ch<='z'))
		ch=ch-'a'+'A';
	printf("%c\n", ch);
}

