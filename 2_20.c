#include <stdio.h>
int main(int argc, char**argv)
{
	printf("before funtion call\n");
	func();	/*함수 호출 */
	printf("after function call\n");
}
/*함수 정의 */
void func()
{
	printf("running function\n");
}

