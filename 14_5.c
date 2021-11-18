#include <stdio.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char**argv)
{
	time_t old, new;
	time(&old);
	sleep(5);
	time(&new);

	printf("%f\n", difftime(new, old));
}

