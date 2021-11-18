#include <stdio.h>
#include <string.h>

int main(int argc, char**argv)
{
	int n;
	n = strspn("seoulKorea", "elmnopsu");
	printf("%d\n", n);
}

