#include "friend2.h"
#include <stdlib.h>
#include <ctype.h>

void put_list(FRIEND_T fr, int fd, int pg);
int read_line(int fd, char*buf, int bufsize);
int add_friend(FRIEND_T fr, int fd, int th);
int edit_friend(FRIEND_T fr, int fd);
void page_friend(FRIEND_T fr,int fd, int num);
void delete_friend(FRIEND_T fr, int fd);
FRIEND_T fr;


int main(int argc, char**argv)
{
	int fd,th;
	int pg=1;
	int num;
	char buf[256];
	if((fd=open(FR_FNAME, O_RDWR))==-1){
		perror("open failed");
		exit(1);
	}
	bzero(&fr, sizeof(fr));

	put_list(fr, fd, pg);

	while(1){
		read_line(0, buf, sizeof(buf));	
		printf("\n");
		if(isdigit(*buf)){
			num =atoi(buf);
			page_friend(fr, fd, num);
			printf("command>> ");
			fflush(stdout);
		}
		else if(!strcmp(buf, "q"))	//q:나가기
			break;
		else if(strcmp(buf,"ls")==0){	//ls:초기화면
			put_list(fr,fd,1);
		}
		else if(strcmp(buf, "next")==0){ //next:다음 페이지
			++pg;
			put_list(fr, fd,pg);
		}
		else if(strcmp(buf,"pre")==0){	//pre: 이전 페이지 
			--pg;
			put_list(fr, fd, pg);	
		}
		else if(strcmp(buf, "n")==0){
					//n: 친구 추가
			th = lseek(fd,0,SEEK_END)/sizeof(fr);
			add_friend(fr, fd,th);
		}
		else if(strcmp(buf,"d")==0){	//친구 삭제 
			delete_friend(fr, fd);
			put_list(fr, fd, pg);
		}			
		else if(strcmp(buf,"e")==0){
			edit_friend(fr, fd);
			//put_list(fr, fd, pg);
		}	
		
	}		 
	close(fd);
		
}

int edit_friend(FRIEND_T fr, int fd)	//수정함수
{
	char en[100];
	bzero(en,sizeof(en));
	printf("수정할 친구 번호를 입력하시오:");
	fflush(stdout);
	read_line(0,en,sizeof(en));

	int ien=atoi(en);
	lseek(fd, sizeof(fr)*ien, SEEK_SET);
	read(fd,&fr, sizeof(fr));
	
	page_friend(fr, fd, ien);
	printf("n=이름,e=이메일 p=전화번호, o=나이 a=주소\n");
	fflush(stdout);
	char buf[100];
	read_line(0, buf, sizeof(buf));

	char *buff;
	buff=strchr(buf,'=');
	char *ans =buff+1;
	int parm=*(buff-1);

	switch(parm){
		case 'a':               //address
                         strcpy(fr.addr, ans);
                         break;
                case 'p':               //phone
                         strcpy(fr.phone, ans);
                         break;
                case 'o':               //age (old)
                         strcpy(fr.age,ans);
                         break;
		case 'n':
			 strcpy(fr.name, ans);
			 break;
		case 'e':
			 strcpy(fr.email, ans);
			 break;
		default:
			 break;
	}
	lseek(fd, sizeof(fr)*ien, SEEK_SET);
	write(fd, &fr, sizeof(fr));
	printf("command>> ");
	fflush(stdout);
		

}

void delete_friend(FRIEND_T fr, int fd)	//삭제함수
{
	char dn[100];

	bzero(dn, sizeof(dn));

	printf("삭제할 친구 번호를 입력하시오:");
	fflush(stdout);
	read_line(0, dn, sizeof(dn));

	int idn= atoi(dn);
	lseek(fd, sizeof(fr)*idn, SEEK_SET);
	read(fd, &fr, sizeof(fr));

//	free(fr);
	bzero(&fr, sizeof(fr));	
//	strcpy(fr.name, 0);

	lseek(fd, sizeof(fr)*idn, SEEK_SET);
	write(fd, &fr, sizeof(fr));

	printf("%s",dn);
	fflush(stdout);
	
}



void put_list(FRIEND_T fr, int fd, int pg)
{
	int re;		
	int i;	//순번 0~100까지
	printf("《번호\t이름\tE-mail\t\t전화번호\t나이\t주소》\n");
	printf("--------------------------------------------------------------- \n");
	for(i=15*(pg-1); i<15*pg; i++){
		re=lseek(fd,i*sizeof(fr),SEEK_SET);
		if(re<0){
			printf("Not found Pass\n");
			break;
		}
		re=read(fd, &fr, sizeof(fr));
		if(re<sizeof(fr)){
			bzero(&fr,sizeof(fr));
		}
		printf("  %d\t%s\t%s\t%s\t%s\t%s \n",i,fr.name, fr.email, fr.phone,fr.age,fr.addr);
	}
	printf(" --<-<-<@  --<-<-<@  --<-<-<@  --<-<-<@  --<-<-<@  --<-<-<@\n");
	printf("---------------------------------------------------------------\n");
printf("command>> ");
fflush(stdout);
}

int read_line(int fd, char*buf, int bufsize)
{
	char c;
	int i,rc;
	bzero(buf, bufsize);
	for(i=0; ;i++){
		rc=read(fd, &c, 1);
		if(rc<=0||c=='\n')
			break;
		if(i<(bufsize-1))
			*(buf+i)=c;
	}
	return i;
}
int add_friend(FRIEND_T fr, int fd,int th)	
{	
	
	char n[256];
	char e[256];
	char p[256];
	char o[256];
	char a[256];
	lseek(fd,0,SEEK_END);
	read(fd,&fr, sizeof(fr));

	printf(" --<-<-<@  --<-<-<@  --<-<-<@  --<-<-<@  --<-<-<@  --<-<-<@\n");
	printf("%d 번째 등록\n",th);  
	printf("이름을 입력하시오:");
	fflush(stdout);
	

	read_line(0, n, sizeof(n));
	printf("%s", n);
	strcpy(fr.name, n);
	fflush(stdout);
	
	printf("\n");

	printf("이메일을 입력하시오:");
	fflush(stdout);

	read_line(0,e,sizeof(e));
	printf("%s", e);
	strcpy(fr.email,e);
	fflush(stdout);
	
	printf("\n");
	printf("전화번호를 입력하시오:");
	fflush(stdout);

	read_line(0,p,sizeof(p));
	printf("%s", p);
	strcpy(fr.phone,p);
	fflush(stdout);

	printf("\n");
	printf("나이를 입력하시오:");
	fflush(stdout);

	read_line(0,o,sizeof(o));
	printf("%s", o);
	strcpy(fr.age,o);
	fflush(stdout);

	printf("\n");
	printf("주소를 입력하시오:");
	fflush(stdout);

	read_line(0,a,sizeof(a));
	printf("%s", a);
	strcpy(fr.addr,a);
	fflush(stdout);

//	lseek(fd, sizeof(fr)*th, SEEK_SET);
	write(fd, &fr, sizeof(fr));
	printf(" command>>");
	fflush(stdout);

}
void page_friend(FRIEND_T fr,int fd, int num)
{	
	lseek(fd, sizeof(fr)*num, SEEK_SET);
	read(fd, &fr, sizeof(fr));
	
	printf("---------------《%d 번의 신상 페이지》------------\n",num);
	printf("   이름     : %s\n", fr.name);
	printf("   이메일   : %s\n",fr.email);
	printf("   전화번호 : %s\n",fr.phone);
	printf("   나이     : %s\n", fr.age);
	printf("   주소     : %s\n", fr.addr);
	printf(" --<-<-<@  --<-<-<@  --<-<-<@  --<-<-<@  --<-<-<@ \n");
        printf("--------------------------------------------------\n");
	
}
