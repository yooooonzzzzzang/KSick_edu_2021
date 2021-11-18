#include <stdio.h>
#include <stdlib.h>

int main(int argc, char**argv, char**envp)
{
	while(*envp)
		printf("%s\n", *envp++);
}

