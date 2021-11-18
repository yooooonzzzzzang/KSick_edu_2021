#include <stdio.h>
#include <stdlib.h>

int main(int argc, char**argv)
{
	printf("%d\n", atoi("-567"));
	printf("%d\n",atoi("\t12345"));
	printf("%d\n",atoi("6377abc"));
}

