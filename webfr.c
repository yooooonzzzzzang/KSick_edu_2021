/*웹에서 동작하는 친구관리 프로그램 */

#define BUFSIZE 512
#define count 10
#define HEADER_FMT "HTTP/1.1 %d %s\nContene-Length: %ld\nContent-Type: %s\n\n"
#define SHOW_FR_LIST "<li>%s\t%s\t%s\t%s\t%s</li>"
#define NOT_FOUND_CONTENT "<h1>404 NOT FOUND</h1>\n"
#define SERVER_ERROR_CONTENT "<h1>500 Internal SErver Error</h1>\n"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "friend2.h"

FRIEND_T fr;

int bind_sock(int sock, int port);
void fill_header(char *header, int status, long len, char*type);
char *find_mime(char *url);
void handle_404(int asock);
void handle_500(int asock);
void http_handler(int asock);

//list.html 파일 만들기
void list_fr(int page)
{
	int fd, li;
	char buf[BUFSIZE];
	char *buf2;

	if((fd=open(FR_FNAME, O_RDWR, 0644)) == -1){
		perror("open failed");
		exit(1);
	}
	if((li=open("list.html", O_RDWR, 0644)) == -1){
			perror("open fialed list.html");
			exit(1);
	}
	lseek(fd, (page-1)*10*sizeof(fr), SEEK_SET);
        sprintf(buf, "<html><head><meta charset=\"utf-8\"><title>friend list page</title></head><body>");
        write(li,buf,strlen(buf));

        sprintf(buf, "<h2>친구목록 %d 페이지<h2><p>", page);
        write(li,buf, strlen(buf));

        for(int i=0; i<count; i++){
                if(read(fd, &fr, sizeof(fr))<=0){
                //더 이상 읽을 친구 목록이 없을 경우 처리하는 코드 작성하기.
                	if((buf2=(FRIEND_T *)malloc((count-i)*64))==NULL)
				exit(1);
			memset(buf2, ' ', (count-i)*64);
			write(li, buf2, strlen(buf2));
			
			printf("end .... \n");
			free(buf2);
                        break;
                }else{
                        bzero(buf, sizeof(buf));
                        sprintf(buf, SHOW_FR_LIST,((page-1)*10)+i, fr.name);
                        write(li,buf,strlen(buf));
                }
        }
        bzero(buf, sizeof(buf));
        sprintf(buf, "</p></body></html>             ");
        write(li,buf,strlen(buf));

	close(fd); close(li);
}

//view.html파일 만들기
void view_fr(int index){
	int fd, vi;
	char buf[BUFSIZE];

	if((fd=open(FR_FNAME, O_RDWR, 0644))==-1){
		perror("open failed");
		exit(1);
	}
	if((vi=open("view.html", O_RDWR, 0644))==-1){
		perror("open failed");
		exit(1);
	}
	lseek(fd, index*sizeof(fr), SEEK_SET);
	read(fd, &fr, sizeof(fr));
	
	sprintf(buf,"<html><head><meta charset=\"utf-8\"><title>friend view page</title></head><body>");
	write(vi, buf, strlen(buf));

	sprintf(buf, VIEW_FR, fr.name, fr.name, fr.age, fr.addr, fr.email, fr.phone);
	write(vi,buf,strlen(buf));

	close(fd);close(vi);
}
int main(int argc, char**argv)
{
	int port, pid;
	int servSock, clntSock;

	struct sockaddr_in servAddr;
	socklen_t serv_len;

	if(argc<2){
		printf("Usage : \n");
		printf("\t%s {port}: runs mini HTTP server. \n", argv[0]);
		exit(1);
	}
	port = atoi(argv[1]);
	printf("[INFO] The server will listen to port: %d.\n", port);
	servSock = socket(AF_INET, SOCK_STREAM, 0);
	if(servSock<0){
		perror("[ERR] failed to create servSock.\n");
		exit(1);
	}
	if(bind_sock(servSock, port)<0){
		perror("[ERR] failed to bind servSock.\n");
		exit(1);
	}
	signal(SIGCHLD, SIG_IGN);

	while(1){
		printf("[INFO] waiting ... \n");

		clntSock= accept(servSock, (struct sockaddr *)&servAddr, &serv_len);
		if(clntSock<0){
			perror("[ERR] failed to accept.\n");
			continue;
		}

		pid = fork();

		if(pid == 0){
			close(servSock);
			http_handler(clntSock);
			close(clntSock);
			exit(0);
		}
		if(pid != 0)
			close(clntSock);
		if(pid <0)
			perror("[ERR] failed to fork.\n");
	}
}
int bind_sock(int sock, int port)
{
	struct sockaddr_in sin;

	sin.sin_family = AF_INET;
	sin.sin_addr.s_addr = htonl(INADDR_ANY);
	sin.sin_port = htons(port);

	return bind(sock, (struct sockaddr *) &sin, sizeof(sin));
}

void fill_header(char *header, int status, long len, char *type)
{
	char status_text[40];
	switch(status){
		case 200:
			strcpy(status_text, "OK"); break;
		case 404:
			strcpy(status_text, "NOt Found");break;
		default:
			strcpy(status_text, "Internal Server Error"); break;
	}
	sprintf(header, HEADER_FMT, status, status_text, len, type);
}
char *find_mime(char *fpath)
{
	char *t, *ctype = "None";
	int i =0;
	char *mts[] = {
		"txt", "text/plain",
		"htm", "text/html",
		"html","text/html",
		"css", "text/css",
		"js", "text/javascript",
		"jpg", "image/jpeg",
		"png", "image/png",
		"gif", "image/gif",
		NULL, NULL};

	t=strrchr(fpath, ".");
	if(!t){
		return ctype;
	}
	if(strchr(t, '/')){
		return ctype;
	}
	for(t++;mts[i];i+=2){
		if(!strcasecmp(t,mts[i])){
			return mts[i+1];
		}
	}
	return ctype;
}
void handle_404(int clntSock)
{
	char header[BUFSIZE];
	fill_header(header, 404, sizeof(NOT_FOUND_CONTENT),"text/html");
	write(clntSock, header, strlen(header));
	write(clntSock, NOT_FOUND_CONTENT, sizeof(SERVER_ERROR_CONTENT));
}

void http_handler(int clntSock)
{
	char header[BUFSIZE];
	char buf[BUFSIZE];

	if(read(clntSock, buf, BUFSIZE)<0){
		perror("[ERR] Failed to read request. \n");
		handle_500(clntSock);







//show.html 파일 만들기
void show_fr(int page)
{
	int fd, sh;
	char buf[BUFSIZE];

	if((fd=open(FR_FNAME, O_RDWR, 0644)) ==-1){
		perror("open failed");
		exit(1);
	}
	if((sh=open("show.html", O_RDWR, 0644)) == -1){
		perror("open failed show.html");
		exit(1);
	}
	lseek(fd, (page-1)*10*sizeof(fr), SEEK_SET);
	sprintf(buf, "<html><head><meta charset=\"utf-8\"><title>friend show page</title></head><body>");
	write(sh,buf,strlen(buf));

	sprintf(buf, "<h2>친구목록 %d 페이지<h2><h4>이름/나이/주소/성별/연락처</h4><p>", page);
	write(sh,buf, strlen(buf));
	for(int i=0; i< 10; i++){
		if(read(fd, &fr, sizeof(fr))<=0){
		//더 이상 읽을 친구 목록이 없을 경우 처리하는 코드 작성하기.
			printf("end .... \n");
			break;
		}else{
			bzero(buf, sizeof(buf));
			sprintf(buf, SHOW_FR_LIST, fr.age, fr.name, fr.addr, fr.email, fr.phone);
			write(sh,buf,strlen(buf));
		}
	}
	bzero(buf, sizeof(buf));
	sprintf(buf, "</p></body></html>             ");
	write(sh,buf,strlen(buf));
}

int main(int argc, char*argv[])
{
	int port, pid;
	int servSock_in servAddr;

	struct sockaddr_in servAddr;
	socklen_t serv_len;

	if(argc<2){
		printf("Usage: \n");
		printf("\t%s {port}: runs mini HTTP server.\n", argv[0]);
		exit(1);
	}
	port = atoi(argv[1]);
	printf("[INFO] The server will listen to port: %d.\n", port);

	servSock = socket(AF_INET, SOCK_STREAM, 0);
	if(servSock <0){
		perror("[ERR] failed to create servSock.\n");
		exit(1);
	}
	if(bind_sock(servSock, port) <0){
		perror("[ERR] failed to bind servSock. \n");
		exit(1);
	}
	if(read(clntSock,buf, BUFSIZE)<0){
		perror("[ERR] Failed to read request.\n");
		handle_500(clntSock);
		return;
	}

	char *method = strtok(buf, " ");
	char *url = strtok(NULL, " ");

	if(method == NULL || url == NULL){
		perror("[ERR] Failed to identify method, URL.\n");
		handle_500(clntSock);
		return;
	}
	printf("[INFO] Handling Request : method=%s, URL = %s\n", method, url);

	char safe_url[BUFSIZE];
	char *local_url, *tmp;
	struct stat st;
	int num =0 ;

	strcpy(safe_url, url);
	if(!strcmp(safe_url, "/")) strcpy(safe_url, "/index.html");

	local_url = safe_url+1;

	//fr?list= 숫자 요청 처리
	if(strstr(local_url, "list")){
		tmp=strtok(local_url, "=");
		tmp=strtok(NULL, " ");//몇번째 page 요청인지 구함
		local_url = "list.html";
		view_fr(num);
	}
	if(stat(local_url, &st)<0){
		perror("[WARN] No file found matching URL. \n");
		handle_404(clntSock);
		return;
	}

	int fd = open(local_url, O_RDONLY);
	if(fd <0){
		perror("[INFO] Failed to open \n");
		handle_500(clntSock);
		return;
	}
	int ct_len = st.st_size;
	char *ct_type;

	ct_type = find_mime(local_url);
	fill_header(header, 200, ct_len, ct_type);
	write(clntSock, header, strlen(header));

	int cnt;
	while((cnt = read(fd, buf, BUFSIZE))>0)
		write(clntSock, buf, cnt);
	close(fd);
	printf("[INFO] Print file.\n");
}







































