#include <stdio.h>
int main(int argc, char**argv)
{
	printf("%d\n", 28);	/*10진수 28을 %d(10진 정수) 형태로 출력한다*/
	printf("%d\n", 0734);	/*08진수 734를 %d(10진 정수)형태로 출력한다 */
	printf("%d\n", 0xA1C);	/*16진수 A1C를 %d(10진 정수 ) 형태로 출력한다 */
	printf("%f\n",1.234);	/*소수점 값 1.234를 %f(실수)형태로 출력한다.*/ 
	printf("%f\n", 0.5E-2); /*지수 값 0.5E-2를 %f(실수) 형태로 출력한다 */
}

