#include <stdio.h>
#include <time.h>

int main(int argc, char**argv)
{
	time_t time_now;
	struct tm *tm;

	time(&time_now);
	tm =localtime(&time_now);
	printf("%02d/%02d/%4d ", tm->tm_mon+1, tm->tm_mday, tm->tm_year+1900);
	 printf("%02d:%02d:%02d\n ", tm->tm_hour, tm->tm_min, tm->tm_sec);
}

