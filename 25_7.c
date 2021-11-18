#include <stdio.h>
#include <stdlib.h>


int main(int argc, char**argv)
{
	FILE *read_fp;
	char buffer[256];

	if((read_fp=popen(argv[1], "r")) == NULL){
		perror("popen failed");
		exit(1);
	}

	while(fgets(buffer, sizeof(buffer), read_fp)) {
		fputs(buffer, stdout);
	}

	pclose(read_fp);
	exit(0);
}

