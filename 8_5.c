#include <stdio.h>
#include <string.h>

int main(int argc, char**argv)
{
	char buf1[20]="Linux";
	char buf2[20] = "Linux";

	strcat(buf1, "Programming");
	strncat(buf2, "Programming", 5);
	printf("%s\n%s\n", buf1, buf2);
}

