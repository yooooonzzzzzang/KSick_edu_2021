#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLESIZE 5
#define ELEMENTSIZE 10

int compare(const void *a, const void *b);

int main(int argc, char**argv)
{
	char table[TABLESIZE][ELEMENTSIZE] = {"C", "Html", "Java", "Perl", "XML"};
	char *ptr;
	if((ptr=(char *)bsearch("Java", table, TABLESIZE, ELEMENTSIZE, compare))==NULL)
		printf("Not found\n");
	else
		printf("%s\n", ptr);
	if((ptr=(char *)bsearch("Linux", table, TABLESIZE, ELEMENTSIZE, compare))==NULL)
		printf("Not found\n");
	else
		printf("%s\n", ptr);
}
int compare(const void *a, const void *b)
{
	return strcmp((char *)a, (char *)b);
}

