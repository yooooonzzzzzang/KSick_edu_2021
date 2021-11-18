#include <stdio.h>
void func();	/*func 라는 함수가 있다는 내용을 컴파일러에 알려주기 위해 함수 선언 */
int main(int argc, char**argv)
{
	printf("before function call\n");
	func();	/*func 함수의 선언과 정의가 되어 있으믈 ㅗ함수 호출에 성공한다 */
	printf("after function call\n");
}
void func()	/* 함수 정의 */
{
	printf("running function\n");
}
