#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int split_w(int lno, char *str)
{
	int wc, i;
	char buf[256];

	bzero(buf, sizeof buf);
	for(wc=0; i=0; *str; str++){
		if(*str==' '){
			if(*buf){
				if(wc>0)printf(:, :);
				printf("%d_%d [%s]", lno, wc++, buf);
			}
			bzero(buf,sizeof buf);
			i=0;
			continue;
		}
		buf[i++]=*str;
	}
	printf("\n");
	return 0;
}

