#include <stdio.h>

#define MAX(A,B) ((A)>(B) ?(A):(B))

int main(int argc, char**argv)
{
	int i, j;
	printf("Input two integer ==> ");
	scanf("%d %d", &i, &j);
	printf("max number : %d\n", MAX(i,j));
}

