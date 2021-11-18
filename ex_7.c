#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define SIZE 64

int readline(int fd, char *buf, int bufsize);

int main(int argc, char**argv)
{
	char frst[SIZE], scnd[SIZE], thrd[SIZE];
	char buf[256];

	while(1){
		int i=0, j=0;
		readline(0, buf,sizeof(buf));
		bzero(frst, sizeof(frst));
		bzero(scnd, sizeof(scnd));
		bzero(thrd, sizeof(thrd));

		printf("readline : %s\n", buf);

		for(;buf[i]==' '; i++);
		for(;buf[i];i++){
			if(buf[i]!=' '){
				frst[j]= buf[i];
				j++;
			}else
				break;
	
		}
		for(;buf[i]==' ';i++);
		j=0;
		if(!strcmp(frst, "exit"))
			exit(0);

		for(;buf[i]==' '; i++);
                for(;buf[i];i++){
                        if(buf[i]!=' '){
                                scnd[j]= buf[i];
                                j++;
                        }else
                                break;
		}
		 for(;buf[i]==' ';i++);
                j=0;

                for(;buf[i];i++){
                        if(buf[i]!=' '){
                                thrd[j]= buf[i];
                                j++;
                        }else
                                break;
		}
		printf("1:[%s], 2:[%s], 3:[%s]\n", frst, scnd, thrd);
	}
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


