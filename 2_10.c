#include <stdio.h>
int main(int argc, char**argv)
{
	/*sizeof 는 데이터형의 크기를 알아내는 연산자로 단위는 바이트 수 */
	printf("int: %ld\n", sizeof(double));
	printf("short: %ld\n", sizeof(short));
	printf("long: %ld\n", sizeof(long));
	printf("unsigned: %ld\n", sizeof(unsigned));
}

