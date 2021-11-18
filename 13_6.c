#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLESIZE 5
#define ELEMENTSIZE 15

int compare(const void *a, const void *b);

int main(int argc, char**argv)
{
	int i;
	char table[TABLESIZE][ELEMENTSIZE] = {"Hello", "Linux", "C", "Programming", "Java"};

	qsort(table, TABLESIZE, ELEMENTSIZE, compare);

	for(i=0; i<TABLESIZE; i++)
		printf("%s\n", table[i]);
}
int compare(const void *a, const void *b)
{
	return strcmp((char *)a, (char *)b);
}

