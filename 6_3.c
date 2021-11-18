#include <stdio.h>

int main(int argc, char**argv)
{
	union position{
		int class;
		char department[10];
	}my;
	int chk;
	
	printf("select number (highschool : 1, university : 2) ==> ");
	scanf("%d", &chk);


	if(chk == 1){
		printf("class ==> ");
		
		scanf("%d", &(my.class));
	}else { 
		printf("major ==> ");
		scanf("%s", my.department);

	}

	if(chk ==1){
		printf("highschool : %d class\n", my.class);
	}else {
		printf("university : %s major\n", my.department);
	}
}


