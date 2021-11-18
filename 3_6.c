#include <stdio.h>

void printbit(char ch);

int main(int argc, char**argv)
{
	char a, b, c;
	int select;

	while(1){
		printf("\nselect menu: 1.AND, 2.OR, 3. XOR, 4. exit = > ");
		scanf("%d", &select);

		if(select ==1){
			printf("Input two characters =>");
			scanf("\n%c %c", &a, &b);
			c =a&b;
			printbit(a);
			printf("AND");
			printbit(b);
			printf("=");
			printbit(c);
		}else if(select ==2){
			printf("input two characters =>");
			scanf("\n%c %c", &a, &b);
			c=a|b;
			printbit(a);
			printf("OR");
			printbit(b);
			printf("=");
			printbit(c);
		}else if(select == 3){
			printf("input two characters =>");
			scanf("\n%c %c", &a, &b);
			c=a^b;
			printbit(a);
			printf("XOR");
			printbit(b);
			printf("=");
			printbit(c);
		}else if(select ==4){
			break;
		}else{
			printf("select error \n");
		}
	}
}
void printbit(char ch)
{ 
	int i;
	for (i=0; i<8; i++){
		printf("%d", (ch&0200)?1:0);
	}
}

