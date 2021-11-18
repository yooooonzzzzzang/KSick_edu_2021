#include <stdio.h>
#include <string.h>
#include <unistd.h>
int readline(int fd, char *buf, int bufsize);	

int main(int argc, char**argv)
{
	char buf[256];
	char *quit ="quit";

	for(;;){
		readline(0,buf,sizeof(buf));
		printf("%s\n", buf);
		if(!memcmp(buf,quit,4))
			break;
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
	
