#include <stdio.h>
#include <time.h>

int main(int argc, char**argv)
{
	time_t time_now;
	time(&time_now);
	printf("%ld\n", time_now);
}


