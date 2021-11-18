#include <stdio.h>
#include <search.h>
#include <string.h>

#define TABLESIZE 10
#define ELEMENTSIZE 15

int compare(const void *a, const void *b);

int main(int argc, char**argv)
{
	char table[TABLESIZE][ELEMENTSIZE] ={"Hello", "Linux", "C"};
	char *ptr;
	long unsigned int datanum =3;

	if((ptr=(char *)lfind("Linux", table, &datanum, ELEMENTSIZE, compare))==NULL)
		printf("Not found\n");
	else
		printf("%s\n", ptr);

	if((ptr=(char *)lfind("Programming", table, &datanum, ELEMENTSIZE, compare))==NULL)
		printf("Not found\n");
	else
		printf("%s\n", ptr);
}
int compare(const void *a, const void *b)
{
	return strcmp((char *)a, (char *)b);
}

