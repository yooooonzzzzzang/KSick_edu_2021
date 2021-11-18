#include "friend.h"
#include <stdlib.h>
int main(int argc, char**argv)
{

	/*./fr2 0=16 2=8 5=17 4=16 
	 * 나이를 칸에 따라 입력해서 friend.dat에 저장하고 읽어서 출력
	 * open -> for() lseek read lseek write  */
        FRIEND_T fr;

        int i, fd, re;
        char *buf;	
        printf("size %d bytes\n", (int)sizeof(FRIEND_T));

        fd = open(FR_FNAME, O_WRONLY|O_CREAT, 0644);
        if(fd<=0) return -1;

        for(i=0; i<10; i++){
                bzero(&fr, sizeof(fr));
                fr.age =10+i;
                re=write(fd, &fr, sizeof(fr));
                if(re<sizeof(fr)) return 0;
        }
        close(fd);		

        fd = open(FR_FNAME, O_RDONLY);
        if(fd<0) return -1;

        for(i=0; i<10; i++){
                int rc;
		bzero(&fr, sizeof(fr));
               /* rc=read(fd, &fr, sizeof(fr));
                if(rc<1)
			break;*/
		read(fd, &fr, sizeof(fr));
		printf("age : %d\n", fr.age);
		
        }
        close(fd);
	printf("*************************************************\n");

	if((fd=open(FR_FNAME,O_RDWR))==-1){
		perror("open failed");
		exit(1);
	}
	for(int i=1; i<argc; i++){
		buf =strchr(argv[i], '=');
		buf++;

		int th =(atoi(argv[i]));
		int age =(atoi(buf));
		
		lseek(fd, sizeof(fr)*th, SEEK_SET);

		read(fd, &fr, sizeof(fr));
		fr.age=age;
		lseek(fd, sizeof(fr)*th, SEEK_SET);
		write(fd, &fr, sizeof(fr));
	}
	close(fd);

	fd = open(FR_FNAME, O_RDONLY);
	while(read(fd,&fr, sizeof(fr)) >0) {
		printf("age : %d\n", fr.age);
	}
	close(fd);
}
