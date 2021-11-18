#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>

#include "friend.h"


int main(int argc, char *argv[])
{

	int fd;
	char *buf;
	int parm;
	FRIEND_T fr;
	char *address=0;		// 바꿀 address
	char *email = 0;
	char *name = 0;
	char *phone = 0;
	

	if (argc < 2 ) {
		perror("argc failed");
		exit(1);
	}

	if ((fd = open("test222.c", O_RDWR)) == -1 ) {
		perror("open failed");
		exit(1);
	}
	

/*

	buf = strchr(argv[1], '=');
	address = buf+1;
	printf("주소 : %s\n", buf+1);
	printf("주소 : %s\n", address);

	int th = atoi(argv[1]);
	printf("몇 번째 구조체? : %d\n", th);

	parm = *(buf-1);
	printf("switch parameter : %d\n", parm);

	lseek(fd, th*sizeof(fr), SEEK_SET);
	read(fd, &fr, sizeof(fr));

	strcpy(fr.address, address);
	printf("address : %s\n", fr.address);

	lseek(fd, th*sizeof(fr), SEEK_SET);
	write(fd, &fr, sizeof(fr));

	printf("fr.address : %s\n", fr.address);
*/


	for (int i = 1; i < argc ; i++) {

		buf = strchr(argv[i], '=');

		int th = atoi(argv[i]);

		parm = *(buf-1);

		bzero(&fr, sizeof(fr));


		switch (parm) {
			case 'a' :
				address = buf+1;
				lseek(fd, th*sizeof(fr), SEEK_SET);
				read(fd, &fr, sizeof(fr));

				strcpy(fr.address, address);
				lseek(fd, th*sizeof(fr), SEEK_SET);
				write(fd, &fr, sizeof(fr));

				
				printf("fr.age : %d\n", fr.age);
				printf("fr.name : %s\n", fr.name);
				printf("fr.adress : %s\n", fr.address);
				printf("fr.phone : %s\n", fr.phone);
				printf("fr.gender : %d\n", fr.gender);
				printf("fr.email : %s\n", fr.email);
				printf("-----------------------------\n");
				
				break;

			case 'e' :
				email = buf+1;
				lseek(fd, th*sizeof(fr), SEEK_SET);
				read(fd, &fr, sizeof(fr));

				strcpy(fr.email, email);
				lseek(fd, th*sizeof(fr), SEEK_SET);
				write(fd, &fr, sizeof(fr));

				
				printf("fr.age : %d\n", fr.age);
				printf("fr.name : %s\n", fr.name);
				printf("fr.adress : %s\n", fr.address);
				printf("fr.phone : %s\n", fr.phone);
				printf("fr.gender : %d\n", fr.gender);
				printf("fr.email : %s\n", fr.email);
				printf("-----------------------------\n");
				
				break;

			case 'p' :
				phone = buf+1;
				lseek(fd, th*sizeof(fr), SEEK_SET);
				read(fd, &fr, sizeof(fr));

				strcpy(fr.phone, phone);
				lseek(fd, th*sizeof(fr), SEEK_SET);
				write(fd, &fr, sizeof(fr));

				
				printf("fr.age : %d\n", fr.age);
				printf("fr.name : %s\n", fr.name);
				printf("fr.adress : %s\n", fr.address);
				printf("fr.phone : %s\n", fr.phone);
				printf("fr.gender : %d\n", fr.gender);
				printf("fr.email : %s\n", fr.email);
				printf("-----------------------------\n");
				
				break;

			case 'n' :
				name = buf+1;
				lseek(fd, th*sizeof(fr), SEEK_SET);
				read(fd, &fr, sizeof(fr));

				strcpy(fr.name, name);
				lseek(fd, th*sizeof(fr), SEEK_SET);
				write(fd, &fr, sizeof(fr));

				
				printf("fr.age : %d\n", fr.age);
				printf("fr.name : %s\n", fr.name);
				printf("fr.adress : %s\n", fr.address);
				printf("fr.phone : %s\n", fr.phone);
				printf("fr.gender : %d\n", fr.gender);
				printf("fr.email : %s\n", fr.email);
				printf("-----------------------------\n");
				
				break;
		}
	}
		close(fd);

		if ((fd = open("test222.c", O_RDONLY)) == -1 ) {
			perror("open failed");
			exit(1);
		}
		while(read(fd, &fr, sizeof(fr)) > 0 ) {

			printf("fr.age : %d\n", fr.age);
			printf("fr.name : %s\n", fr.name);
			printf("fr.adress : %s\n", fr.address);
			printf("fr.phone : %s\n", fr.phone);
			printf("fr.gender : %d\n", fr.gender);
			printf("fr.email : %s\n", fr.email);
			printf("- - - - - - - - - - - - \n");
		}
		close(fd);
		
}







