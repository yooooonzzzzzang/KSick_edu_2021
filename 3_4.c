#include <stdio.h>
int main(int argc, char**argv)
{
	int i, fac, n;
	i=fac=1;
	printf("Input number ==> ");
	scanf("%d", &n);
	while (i<=n){
		fac*=i++;
	}
	printf("%d factorial : %d\n", n, fac);
}


