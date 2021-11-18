#include <stdio.h>
#include <string.h>

int main(int argc, char**argv)
{
	char *str="Hello linux Programming, Linuxer";
	char *ptr;
	
	ptr =strstr(str,"linux");
	printf("%s\n",ptr);
}


