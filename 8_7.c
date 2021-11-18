#include <stdio.h>
#include <string.h>
#define MAX 20

int main(int argc, char**argv)
{
	char buffer1[MAX];
	char buffer2[MAX];
	strcpy(buffer1, "Linux");
	printf("%s\n", buffer1);
	strcpy(buffer2, "Programming");
	printf("%s\n", buffer2);
	strcpy(buffer2, buffer1);
	printf("%s\n", buffer2);
}

