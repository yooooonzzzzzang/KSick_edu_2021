#include <stdio.h>
#define DAY 365
#define TIME 24
#define MINUTE 60
#define SECOND 60

int main(int argc, char**argv)
{
	long int sec;
	sec = DAY*TIME*MINUTE*SECOND;
	printf("one year is %ld second. \n", sec);
}

