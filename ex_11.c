#include "frined.h"
#include <stdlib.h>

int main(int argc, char**argv)
{
	FRIEND_T fr;

	int i, fd;
        char *buf;
/*	
	//기본나이 출력 10~ 19세	
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
               // int rc;
                bzero(&fr, sizeof(fr));
//               rc=read(fd, &fr, sizeof(fr));
//               if(rc<1)
//                        break;
                read(fd, &fr, sizeof(fr));
                printf("age : %d\n", fr.age);

        }
        close(fd);
	printf("\n\n");
*/
	if((fd=open(FR_FNAME, O_RDWR))==-1){
		perror("open failed");
		exit(1);
	}
	for(i=1; i<argc; i++){			//0a=대전 이라면
		int th= atoi(argv[i]);
		//printf("주소값:%d ",th);		//0
		
		buf =strchr(argv[i], '=');		//=
		char *ans = buf+1;			//대전
                //printf("넣을 값:%s ",ans);		

		//buf 가져와서
		int parm= *(buf-1);		//선택 =의 앞부분
		bzero(&fr, sizeof(fr));
				
			
		lseek(fd, sizeof(fr)*th, SEEK_SET);
		read(fd,&fr, sizeof(fr));
		
		switch(parm){		//주소값이
			case 'a':
				printf("dddd\n");		//address
				strcpy(fr.addr, ans);
				break;
			case 'p':		//phone
				strcpy(fr.phone, ans);
				break;
			case 'o':		//age (old)
				fr.age=atoi(ans);
				break;
		}	
		lseek(fd, sizeof(fr)*th, SEEK_SET);
                write(fd, &fr, sizeof(fr));

	}
		close(fd);
	


		fd = open(FR_FNAME, O_RDONLY);
	        while(read(fd,&fr, sizeof(fr)) >0) {
        	        printf("age : %d\n", fr.age);
			printf("addres: %s\n", fr.addr);
			printf("phone: %s\n", fr.phone);
			printf("-----------------------\n");
       		 }
     		 close(fd);

	}







