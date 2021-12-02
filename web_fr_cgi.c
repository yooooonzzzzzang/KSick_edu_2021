/*
파일명: web_fr_cgi.c
파일설명: Apache 와 CGI를 활용한 친구관리 프로그램
작성자: park yun ji
작성일: 21/12/2
*/
#define BUFSIZE 1024
#define count 10
#define HEAD_LIST "<html lang=\"ko\"><head><meta charset=\"utf-8\"><title>friend listpage</title></head><body><h2>친구목록 %d 페이지 </h2>"
#define HEAD_VIEW "<html lang=\"ko\"><head><meta charset=\"utf-8\"><title>friend view page</title></head><body><h2>%d 상세페이지 </h2>"
#define HEAD_SEARCH "<html lang=\"ko\"><head><meta charset=\"utf-8\"><title>friend search page</title></head><body><h2>친구검색 페이지</h2>"
#define SHOW_FR_LIST "<a href=\"./web_fr.cgi?view=%d\">%s</a><br>"
#define VIEW_FR "<h2>%s 상세 정보</h2><p><li>이름: %s</li><li>나이: %s</li><li>주소: %s</li><li>성별: %s</li><li>연락처: %s</li></p></body></html>      "

#define SEARCH_BAR "<form action=\"./web_fr.cgi\" accept-charset=\"utf-8\" method=\"get\">검색어:<input type=\"search\" name=\"search\"><input type=\"submit\"></form><p>"
#define SEARCH_FR_LIST "<a href=\"/web_fr.cgi?view=%d\">%s</a><br>"
#define BUTTON_LIST "<br><button onClick=\"location.href='./web_fr.cgi?list=%d'\">이전</button> <button onClick=\"location.href='./web_fr.cgi?list=%d'\">다음</button>"
#define NOT_FOUND_CONTENT "<h1>404 Not Found</h1>\n"
#define SERVER_ERROR_CONTENT "<h1>500 Internal Server Error</h1>\n" 
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

void http_handler();

// url의 16진수를 한글로 decoding하는 함수
int decode_url(char *url)
{
	char *t;

	for(t=url;*url;t++){
		if(*url=='%'){
			char *eptr=url+3;

			*t=strtol(url+1,&eptr,16);
			url+=3;
		}
		else *t=*(url++);
		}
	*t=0l;

	return 0;
}

//list.html 파일 만들기
void list_fr(int page)
{
	int fd;

	if((fd=open("friend2.dat",O_RDWR,0644))==-1){
		perror("<br>friend2.dat open failed");
		exit(1);
	}

	lseek(fd,(page-1)*count*sizeof(fr),SEEK_SET);
	printf(HEAD_LIST, page);
	printf(SEARCH_BAR);

	for(int i=0;i<count;i++){
		if(read(fd,&fr,sizeof(fr))<=0){
/*// 더이상 읽을 친구 목록이 없을 경우 처리하는 코드 작성하기.
if((buf2=(FRIEND_T *)malloc((count-i)*64))==NULL) exit(1);
memset(buf2,' ',(count-i)*64);
write(li,buf2,strlen(buf2));

printf("end.....\n");
free(buf2);*/
			break;
		}else{
			printf(SHOW_FR_LIST,((page-1)*10)+i,fr.name);
		}
}

	if(page==1){
		printf(BUTTON_LIST,page,page+1);
	}else{
		printf(BUTTON_LIST,page-1,page+1);
	}

	printf("</p></body></html>");

	close(fd);

}

// view.html 파일 만들기
void view_fr(int index){
	int fd;

	if((fd=open("friend2.dat",O_RDWR,0644))==-1){
		perror("open failed");
		exit(1);
	}

	lseek(fd,index*sizeof(fr),SEEK_SET);
	read(fd,&fr,sizeof(fr));

	printf(HEAD_VIEW, index);
	printf(VIEW_FR,fr.name, fr.name, fr.age, fr.addr, fr.email, fr.phone);

	close(fd);
}

void search_fr(char *word)
{
	int fd, index=-1,cnt=0;
	char wbuf[BUFSIZE];

	strcpy(wbuf,word);
	decode_url(wbuf);

	if((fd=open("friend2.dat",O_RDWR,0644))==-1){
		perror("open failed");
		exit(1);
		}
------------------------------------------------------------------------------------------
	sprintf(buf,"<html lang=\"ko\"><head><meta charset=\"utf-8\"><title>friend list page</title></head><body><h2>친구검색 페이지</h2>");
	write(se,buf,strlen(buf));

	sprintf(buf,SEARCH_BAR);
	write(se,buf,strlen(buf));

	while(1){
		if(read(fd,&fr,sizeof(fr))<=0){
		break;
		}else{
			index++;
		}
	if(strstr(fr.name,wbuf)){
		bzero(buf,sizeof(buf));
		sprintf(buf, SEARCH_FR_LIST,index,fr.name);
		write(se,buf,strlen(buf));
		cnt++;
	}
}

if(cnt==0){
	sprintf(buf,"검색 결과 없음");
	write(se,buf,strlen(buf));
}
bzero(buf,sizeof(buf));
sprintf(buf,"</p></body></html>            ");
write(se,buf,strlen(buf));

close(fd);close(se);

}

int main(int argc, char *argv[])
{
	printf("Content-type: text/html\n\n");
	http_handler();

	return 0;
}




	perror("[ERR] failed to listen servSock.\n");
	exit(1);
}



void handle_404(int clntSock)
{
	char header[BUFSIZE];
	fill_header(header, 404, sizeof(NOT_FOUND_CONTENT),"text/html");

	write(clntSock, header, strlen(header));
	write(clntSock, NOT_FOUND_CONTENT, sizeof(NOT_FOUND_CONTENT));
}

void handle_500(int clntSock)
{
	char header[BUFSIZE];
	fill_header(header, 500, sizeof(SERVER_ERROR_CONTENT),"text/html");

	write(clntSock, header, strlen(header));
	write(clntSock, SERVER_ERROR_CONTENT, sizeof(SERVER_ERROR_CONTENT));
}

void http_handler(int clntSock)
{
	char header[BUFSIZE];
	char buf[BUFSIZE];

	if(read(clntSock, buf, BUFSIZE)<0){
		perror("[ERR] Failed to read request.\n");
		handle_500(clntSock);
		return;
	}

	char *method = strtok(buf," ");
	char *url = strtok(NULL," ");

if(method == NULL || url == NULL){
	perror("[ERR] Failed to identify method, URL.\n");
	handle_500(clntSock);
	return;
}

printf("[INFO] Handling Request: method=%s, URL=%s\n", method, url);

char safe_url[BUFSIZE];
char *local_url, *tmp;
struct stat st;
int num=0;

strcpy(safe_url, url);
if(!strcmp(safe_url,"/")) strcpy(safe_url,"/index.html");

local_url = safe_url+1;

//fr?list=숫자 요청 처리
if(strstr(local_url,"list")){
	tmp=strtok(local_url,"=");
	tmp=strtok(NULL," "); //몇번째 page 요청인지 구함
	num = atoi(tmp);
	local_url = "list.html";
	list_fr(num);
}
    //fr?view=숫자 요청 처리
if(strstr(local_url,"view")){
	tmp=strtok(local_url,"=");
	tmp=strtok(NULL," "); // 몇번째 사람 정보 요청인지 구함
	num = atoi(tmp);
	local_url = "view.html";
	view_fr(num);
}
//fr?search=이름 요청 처리
if(strstr(local_url,"search")){
	tmp=strtok(local_url,"=");
	tmp=strtok(NULL," ");
	local_url = "search.html";
	search_fr(tmp);
}

if(stat(local_url, &st)<0){
	perror("[WARN] No file found matching URL.\n");
	handle_404(clntSock);
	return;
}

int fd = open(local_url, O_RDONLY);
if (fd < 0){
	perror("[INFO] Failed to open faile.\n");
	handle_500(clntSock);
	return;
}

int ct_len= st.st_size;
char *ct_type;

ct_type = find_mime(local_url); //요청한 파일의 type 확인
fill_header(header, 200, ct_len, ct_type); // 헤더 작성
write(clntSock, header, strlen(header));

int cnt;
while((cnt = read(fd,buf, BUFSIZE))>0)
	write(clntSock, buf, cnt);

close(fd);
printf("[INFO] Print file.\n");
}
