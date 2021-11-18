#include "friend3.h"
#define DATA "Finfo2.dat"
#include <stdlib.h>
void print_list(int fd, int page, FRIEND_T fr);
int readline(int fd, char *buf, int bufsize);
void edit(int fd, FRIEND_T fr);

int check =0;

int main(int argc, char **argv)
{
	FRIEND_T fr;
	char buf[1024];
	int fd;

	if((fd=open(DATA, O_RDWR))==-1){
		perror("open failed");
		exit(1);
	}
	while(1){
		if(check=0){
			system("clear");
			print_list(fd, 1,fr);
			check++;
		}
		printf("command >> ");
		readline(0,buf,sizeof(buf));
		printf("%s\n", buf);

		if(strcmp(buf,"quit")==0){
			check=0;
		}else if(strcmp(buf, "next")==0){
			check++;
			system("clear");
			print_list(fd, check, fr);
		}else if(strcmp(buf, "pre")==0){
			check--;
			system("clear");
			print_list(fd, check, fr);
		}else if(strcmp(buf, "edit")==0){
			printf("Edit Command >");
			edit(fd, fr);
		}
	}
	close(fd);
	return 0;
}

void print_list(int fd, int page, FRIEND_T fr)
{
	int re;
	printf("[Num]\t[Name]\t[age]\t[E-mail]\t\t[Phone]\t\t[Address]\n");
	for(int i=15*(page-1); i<15*page; i++){
		re=lseek(fd, i*sizeof(fr), SEEK_SET);
		if(re<0){
			printf("Not found pass\n");
			break;
		}
		re=read(fd, &fr, sizeof(fr));
		if(re<sizeof(fr)){
			bzero(&fr, sizeof(fr));
		}
		printf("[%02d]\t%s\t%02d\t%s\t%s\t%s\n",
				i,fr.name,fr.age,fr.email,fr.phone,fr.address);	
	}
}

int readline(int fd, char*buf, int bufsize)
{
	char c;
	int i, rc;

	bzero(buf, bufsize);

	for(i=0; ;i++){
		rc=read(fd, &c,1);
		if(rc<=0||c=='\n')
			break;
		if(i<(bufsize-1))
			*(buf+i)=c;
	}
	return i;
}

void edit(int fd, FRIEND_T fr)
{
	char str1[1024], *str2, *str3;
	int changeValue, changeAddress, re;

	char arr1[1024];
	char arr2[100], arr3[1024];
	str2=arr2;
	str3=arr3;

	readline(0, str1, sizeof(str1));
	printf("%s\n", str1);

	str2=strtok(str1, "=");
	if(str2==NULL){
		printf("Not found \"=\" \n");
		exit(1);
	}
	changeAddress = atoi(str2)*sizeof(fr);

	re=lseek(fd, changeAddress, SEEK_SET);
	if(re<0){
		printf("Not Found Pass\n");
		exit(1);
	}
	re=read(fd, &fr, sizeof(fr));
	if(re<sizeof(fr)){
		bzero(&fr, sizeof(fr));
	}

	switch(str2[strlen(str2)-1]){
		case 'o' :
			str3=strtok(NULL, "=");
			changeValue = atoi(str3);
			fr.age = changeValue;
			break;
		case 'n':
			str3=strtok(NULL,"=");
			strcpy(fr.name, str3);
			break;
		case 'p':
			str3=strtok(NULL,"=");
                        strcpy(fr.phone, str3);
                        break;
		case 'a':
			str3=strtok(NULL,"=");
                        strcpy(fr.address, str3);
                        break;
		case 'e':
			str3=strtok(NULL,"=");
                        strcpy(fr.email, str3);
                        break;
		default:
			printf("Not found\n");
			break;
	}
	lseek(fd, changeAddress, SEEK_SET);
	write(fd, &fr, sizeof(fr));
	printf("str3: %s\n", str3);
}
















































