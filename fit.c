#include <string.h>
#include <stdio.h>
int str_fit(char *str, char *bline, int size , int maxc);

int main()
{
	char bline[1024];
	bzero(bline, sizeof(bline));
	int rc = str_fit("아름다운 대한민국" , bline , sizeof(bline), 10);
	printf("bline : %ld ,rc ; %d\n", sizeof(bline),rc);
	str_fit("010-4412-5543", bline, sizeof(bline),24);
	str_fit("aaa@naver.com", bline, sizeof(bline), 38);
	printf(" bline :%s \n", bline);
}






int str_fit(char *str, char *bline, int size, int maxc)
{
	int sc;
	strncat(bline, str, size-strlen(bline));
	printf("func / bline : %s , str : %s \n", bline, str);
	for(sc=0; *bline;){
		int c=0;
		int t=1;
		if(!(*bline & 128)){
			c=1;
		}
		else if(!(*bline & 64)){
			c=1;
		}
		else if(!(*bline & 32)){
			c=2;
			t=2;
		}
		else if(!(*bline & 16)){
			c=2;
			t=3;
		}
		else if(!(*bline & 8)) {
			c=2;
			t=4;
		}
		if(sc+c >= maxc) {
			break;
		}
		sc += c;
		bline += t;
	}
	memset(bline , ' ', maxc *sc);
	*(bline  + maxc - sc) = 0;
	return sc;
}
