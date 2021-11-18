#include "friend.h"
#include <stdlib.h>

void put_list(FRIEND_T fr, int fd, int pg);





int main(int argc,char**argv)
{
	FRIEND_T fr;
	int fd;
	int pg; //페이지번호(1장에 15개씩 넣는다)
	if((fd=open(FR_FNAME, O_RDWR))==-1){
		perror("open failed");
		exit(1);
	}
	

	put_list(fr, fd, pg);

	close(fd);

}
int readline(int fd, char *buf, int bufsize)
{
        char c;
        int i, rc;
        bzero(buf,bufsize);
        for(i=0; ;i++){
                rc=read(fd, &c, 1);
                if(rc <=0)
                        break;
                if(c=='\n')
                        break;
                if(i< bufsize-1)
                        *(buf+i) =c;
        }
                return i;
}

void put_list(FRIEND_T fr,int fd,int pg)
{
	int n=0;	
	printf("번호\t이름\tE-mail\t\t전화번호\t나이\t주소\n");
	printf("------------------------------------------------------------\n");

	printf("%d\t%s\t%s\t\t\t%s\t\t%d\t%s\n", n,fr.name, fr.email, fr.phone,fr.age,fr.addr);
	printf("------------------------------------------------------------\n");
 
}

put_friend(int fd, int fno){	/* 신상 페이지 */
	printf("-----------------------신상 페이지 ------------------------\n");
	printf("이름 :%s\n");
	printf("E-mail :%s\n");
	printf("전화번호 :%s\n");
	printf("나이 :%d\n");
	printf("주소 :%s\n");

}

add_friend(int fd){
}

