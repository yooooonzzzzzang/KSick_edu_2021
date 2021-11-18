#include <stdio.h>
int main(int argc, char**argv)
{
	int i;
	/*4바이트로 표현할 수 없는 3000000000을 저장하려 하므로 오버플로 발생 */
	i = 1500000000 + 1500000000;
	printf("i : %d\n", i);
}

