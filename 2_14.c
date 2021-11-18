#include <stdio.h>
int main(int argc, char**argv){
	char ch1, ch2; 	/* char형 변수 ch1, ch2 선언 */
	ch1 ='a';
	/* 정수 99를 2진수로 나타내면 1100011 인데 이는 'c' 의 ASCII 코드 값과 같다 */
	ch2 = 99;
	/*문자 형태와 10진 정수 형태로 출력 */
	printf("ch1: %c %d\n", ch1, ch1);
	printf("ch2: %c %d\n", ch2, ch2);
}

