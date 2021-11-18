#include <stdio.h>
#include <string.h>

int main(int argc, char**argv)
{
	char *ptr;

	ptr=strpbrk("seoulKorea", "Ka");
	printf("%s\n", ptr);
}

