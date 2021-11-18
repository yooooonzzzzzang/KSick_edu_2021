#include <stdio.h>
#include <string.h>

int main(int argc, char**argv){
	char buf[20];
	int line =1;

	while(1){
		printf("Input string ==> ");
		scanf("%s", buf);
		if(strcmp(buf, "quit")==0)
			break;
		printf("%2d: %s\n", line++, buf);
	}
}


