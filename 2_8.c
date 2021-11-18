#include <stdio.h>
int main(int argc, char**argv)
{
	/*열거형 months를 정의하고 열거형 변수 mon을 선언한다 */
       enum months { JAN=1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC}mon;
mon =JUL;	/*JUL은 7을 의미하는 기호 상수 */
printf("%d\n",mon);
printf("%d\n",NOV);	/*NOV는 11을 의미하는 기호 상수 */
		}

