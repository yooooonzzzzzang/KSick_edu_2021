#include <stdio.h>

int fibo(int n);

int main(int argc, char**argv)
{
	int n;
	printf("Input number => ");
	scanf("%d",&n);
	printf("%d'th fibonacci number : %d\n", n, fibo(n));
}
int fibo(int n)
{
	if (n ==1 || n==2)
		return 1;
	else
		return fibo(n-1)+fibo(n-2);
}

