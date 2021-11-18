#include <stdio.h>
/* 함수를 사용하기 위해 정의한다 */
void func()
{
	printf("running fuction\n");
}
int main(int argc, char**argv)
{
	printf("before function call\n");
	func();	/* 함수가 실행되도록 호출한다 */
	printf("after function call\n");
}

