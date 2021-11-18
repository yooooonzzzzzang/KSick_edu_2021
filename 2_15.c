#include <stdio.h>
int main(int argc,char**argv)
{
	/*문자열을 저장하는 배열 변수 선언 
	 * 배열의 마지막 요소에는 NULL('\0')문자가 들어가야 하기 때문에
	 * 최대 3개의 문자로 이루어진 문자열 저장 */
	char str[4];
	str[0] = 'a';	str[1]='b';
	str[2]= 'c';	str[3] ='\0';	/*NULL('\0') 문자는 문자열의 끝을 의미 */	printf("%s\n",str);	/*%s 는 문자열 형태로 출력 */
}

