#include <stdio.h>
int main(int argc, char**argv)
{
	/* 변수 선언과 동시에 초기화 */
	int i = 1000;	/*int i; 와 i= 10000; 가 한문장으로 */
	long int j = 100000;
	unsigned int k = 50000;
	printf("i : %d\n",i);
	printf("j : %ld\n",j); /*ld는 long 형을 10 진 정수로 출력 */
	printf("k : %u\n", k); /*u는 unsigned 형을 10진 정수로 출력 */
}

