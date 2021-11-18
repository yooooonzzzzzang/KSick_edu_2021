#include "friend.h"

int main(int argc, char**argv)
{
	FRIEND_T fr;

	int i, fd, re; 
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
		bzero(&fr, sizeof(fr));
		read(fd, &fr, sizeof(fr));
		printf("age : %d\n", fr.age);
	}
	close(fd);
	return 0;
}
