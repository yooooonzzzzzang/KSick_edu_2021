#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	printf("Userid : %d\n", getuid());

	printf("Groupid : %d\n", getgid());
	exit(0);
}

