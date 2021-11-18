#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

int readline(int fd, char*buf, int bufsize);
int split_w(int lno, char*str);

int main(int argc, char**argv)
{
	int fd;
	int rc;
	int i;
	char buf[20];

	if(argc <2){
		perror("파일 이름을 입력하세요 \n");
		exit(1);
	}
	if((fd=open(argv[1], O_RDONLY))==-1){
		perror("open failed");
		exit(1);
	}
	
	for(i=0; i<sizeof(buf);i++){
		rc=readline(fd, buf, sizeof(buf));
		printf("%s\n", buf);
		if(rc=='\0')
			break;
	}
	

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
int split_w(int lno, char *str)
{
	int i, j, wc, lc;
	char **buf;

	for(i=0; str
	


}

