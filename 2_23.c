#include <stdio.h>
/* 함수 선언 func함수가 있다는 내용뿐만이 아니라 int 형 값을 반환할 것이라는 내용을 컴파일러에 알려준다 */
int func();
int main(int argc, char**argv)
{
	int i;
	i=func();	/* 함수 호출, 함수 실행이 끝나면 정수값을 반환 받아 i에 저장한다. */
	printf("%d\n",i);
}
/*반환 값이 있는 함수 정의 */
int func()
{
	return 5+7;	/*5+7의 결과인 12를 반환한다 */
}

