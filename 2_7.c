#include <stdio.h>
#define BUFSIZE 12 /* 기호 상수 정의, BUFSIZE는 12 에 해당하는 기호 상수*/
int main(int argc, char**argv)
{
	/*buf[12]와 동일 , 즉 컴파일하기 전에 BUFSIZE는 12로 바뀐다 */
	char buf[BUFSIZE] = "Programming";
	printf("%s\n", buf);
}

