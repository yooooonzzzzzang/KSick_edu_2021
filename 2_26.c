#include <stdio.h>
void func(void);
int main(int argc, char**argv)
{
	printf("before function call\n");
	func();
	printf("alter function call\n");
}
/*반환값과 매개변수가 없음을 void로 명시하고 함수 정의 */
void func(void)
{
	printf("running function\n");
}

