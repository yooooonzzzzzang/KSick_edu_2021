#include <stdio.h>
int main(int argc, char**argv)
{
	int ch, numl =0, nums =0;
	while((ch=getchar())!= EOF){
		if((ch>='A') && (ch<='Z'))
			numl++;
		else if((ch>='a')&&(ch<='z'))
			nums++;
	}
	printf("%d %d\n", numl, nums);
}
