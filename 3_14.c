#include <stdio.h>

int main(int argc, char**argv)
{
	int a,b, max, min;
	printf("Input integer1 ==> ");
	scanf("%d", &a);
	printf("Input integer2 ==> ");
	scanf("%d", &b);
	if(a>b){
		max =a;
		min =b;
	}else{
		max=b;
		min =a;
	}printf("max:%d\tmin:%d\n", max, min);
}

