#include <stdio.h>

int main(int argc, char**argv)
{
	int a[4][4] = {{1,2,3,0},{4,5,6,0},{7,8,9,0},{0,0,0,0}};
	int i, j;
	for(i=0; i<3; i++)
		for(j=0; j<3; j++){
			a[i][3] += a[i][j];
			a[3][j] += a[i][j];
			a[3][3] += a[i][j];
		}
	for(i=0; i<4; i++)
		for(j=0;j<4; j++)
			printf("%2d%s", a[i][j], (j==3)?"\n":"");
}

