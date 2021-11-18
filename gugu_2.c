#include <stdio.h>
#include <stdlib.h>
int main(int argc, char**argv)
{	
	
	int num;
	int j;
	
	while(1){
	printf("숫자 하나를 입력하세요\n");
	scanf("%d", &num);
	
	if(num ==0){
		exit(0);
	}else if(num>=1&&num<=9)
	{
	for(j=1;j<10; j++)
		printf("%dX%d=%d\n",num,j,num*j);
	}
	}
}

