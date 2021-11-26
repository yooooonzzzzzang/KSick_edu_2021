#define BUF_SIZE 1000
#define HEADER_FMT "HTTP/1.1 %d %s\nContent-Length: %ld\nContent-Type: %s\n\n" 
//HEADER_FMT로 형식을 지정해 %d에 status, %s에 그에 따른 값, 그리고 mime정보를 입력
//HTTP/1.1 : 표준 프로토콜

#define NOT_FOUND_CONTENT "<h1>404 Not Found</h1>\n" //404error에 관란 내용을 문자열로 정의
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

// lsock : server socket / asock : client socket
int bind_lsock(int lsock, int port) {
	struct sockaddr_in sin; 

	sin.sin_family = AF_INET; 
	sin.sin_addr.s_addr = htonl(INADDR_ANY); 
	sin.sin_port = htons(port); 
	/*lsock라는 소켓에 &sin을 연결함(sin이 가리키는 구조체의 크기=sizeof(sin))*/
	return bind(lsock, (struct sockaddr *)&sin, sizeof(sin));
}
void fill_header(char *header, int status, long len, char *type);
void find_mime(char *ct_type, char *uri);
void handle_404(int asock);
void handle_500(int asock);
void http_handler(int asock);

int main(int argc, char **argv) {
	int port, pid; 
	int lsock, asock; 
	
	struct sockaddr_in remote_sin; 
	socklen_t remote_sin_len; //typedef한 것

	if (argc < 2) { // error처리
		printf("Usage: \n"); 
		printf("\t%s {port}: runs mini HTTP server.\n", argv[0]); 
		exit(0); 
} 

	port = atoi(argv[1]); //입력한 port번호를 atoi로 정수형 변환
	printf("[INFO] The server will listen to port: %d.\n", port); 

	lsock = socket(AF_INET, SOCK_STREAM, 0); 

	if (lsock < 0) { //lsock가 없을 시, error처리
		perror("[ERR] failed to create lsock.\n"); 
		exit(1); 
	} 
	if (bind_lsock(lsock, port) < 0) { //bind를 못할 시, error처리
		perror("[ERR] failed to bind lsock.\n"); 
		exit(1);
       	} 
	if (listen(lsock, 10) < 0) { //listen을 못할 시, error처리
		perror("[ERR] failed to listen lsock.\n"); 
		exit(1);
       	} 

	signal(SIGCHLD, SIG_IGN); 
	while (1) { 
		printf("[INFO] waiting...\n"); 
		asock = accept(lsock, (struct sockaddr *)&remote_sin, &remote_sin_len); 
		if (asock < 0) { 
			perror("[ERR] failed to accept.\n"); 
		continue;
	       	} 

		pid = fork(); // 서버에서 자식프로세스 생성
		if (pid == 0) { //pid=0이라는 것은 자식 프로세스를 의미
			close(lsock); 
			http_handler(asock); 
			close(asock); 
			exit(0); 
		} 
		if (pid != 0) { //pid가 0이 아니라는 것은 0이 아닌 양의 정수이므로 부모 프로세스(pid=process ID)
			close(asock); 
		}

		if (pid < 0) {  //pid가 0보다 작다는 것은 -1로 error
			perror("[ERR] failed to fork.\n");
	       	}
       	}
}

void fill_header(char *header, int status, long len, char *type) { 
	char status_text[40]; 
	switch (status) { 
		case 200: //status가 200이라면
			strcpy(status_text, "OK"); 
			break; 
		case 404:
 			strcpy(status_text, "Not Found"); 
			break; 
		case 500:

	       	default: 
			strcpy(status_text, "Internal Server Error"); 
			break;
       	} 
	sprintf(header, HEADER_FMT, status, status_text, len, type);
}	//sprintf해석 : header에 HEADER_FMT라는 형식에 맞춰 status, status_text, len, type을 집어넣음
 
void find_mime(char *ct_type, char *uri) { //mime는 데이터 파일 정보로 만약 local_uri가 있다면 그에 대한 정보(type,크기)를 말함
	char *ext = strrchr(uri, '.'); //ext = .html, 문자열에서 문자가 마지막으로 발견된 위치 검색

	if (!strcmp(ext, ".html")) 
		strcpy(ct_type, "text/html"); //기본 형식은 구글링
	else if (!strcmp(ext, ".jpg") || !strcmp(ext, ".jpeg")) 
		strcpy(ct_type, "image/jpeg"); 
	else if (!strcmp(ext, ".png")) 
		strcpy(ct_type, "image/png"); 
	else if (!strcmp(ext, ".css")) 	
		strcpy(ct_type, "text/css"); 
	else if (!strcmp(ext, ".js")) 
		strcpy(ct_type, "text/javascript"); 
	else strcpy(ct_type, "text/plain");
}  

void handle_404(int asock) {
       	char header[BUF_SIZE]; 

	fill_header(header, 404, sizeof(NOT_FOUND_CONTENT), "text/html");
       	write(asock, header, strlen(header)); 
	write(asock, NOT_FOUND_CONTENT, sizeof(NOT_FOUND_CONTENT)); 
}  

void handle_500(int asock) { 
	char header[BUF_SIZE]; 

	fill_header(header, 500, sizeof(SERVER_ERROR_CONTENT), "text/html"); 
	write(asock, header, strlen(header)); 
	write(asock, SERVER_ERROR_CONTENT, sizeof(SERVER_ERROR_CONTENT)); 
} 

void http_handler(int asock) { 
	char header[BUF_SIZE]; 
	char buf[BUF_SIZE]; 
	
	if (read(asock, buf, BUF_SIZE) < 0) { 
		perror("[ERR] Failed to read request.\n"); 
		handle_500(asock); 
		return; 
	} 
	//printf("BUF=> %s\n",buf);
	//문자열에서 지정한 구분자가 나오면 단어로 자르고 단어의 첫 문자에 대한 포인터 반환
	char *method = strtok(buf, " "); //Get or Post(둘 중에 하나가 method에 들어감)
	char *uri = strtok(NULL, " "); //공백을 기준으로 뒤의 값을 가져와 uri로 저장

	if (method == NULL || uri == NULL) { //error처리
		perror("[ERR] Failed to identify method, URI.\n"); 
		handle_500(asock); 
		return; 
	} 
	
	printf("[INFO] Handling Request: method=%s, URI=%s\n", method, uri); 
	
	char safe_uri[BUF_SIZE]; 
	char *local_uri; 
	struct stat st; 
	
	strcpy(safe_uri, uri); //uri를 safe_uri에 복사
	if (!strcmp(safe_uri, "/")) strcpy(safe_uri, "/index.html"); //기본값(index.html)설정
	
	local_uri = safe_uri + 1; // /me.html에서 +1한 경우는 m부터 읽겠다는 의미
	if (stat(local_uri, &st) < 0) { 
		perror("[WARN] No file found matching URI.\n"); 
		handle_404(asock); 
		return; 
	} 
	
	int fd = open(local_uri, O_RDONLY); //fd는 local_uri를 읽은 것
	if (fd < 0) { //error처리
		perror("[ERR] Failed to open file.\n"); 
		handle_500(asock); 
		return; 
	} 

	int ct_len = st.st_size; //ct_len은 Header에서 크기(byte수)를 의미
	char ct_type[40]; //ct_type은 Header에서 Type(html, gif, pdf, 사진)을 의미

	find_mime(ct_type, local_uri); 
	fill_header(header, 200, ct_len, ct_type);
	write(asock, header, strlen(header)); //위에 세 줄은 mime에서 Header에 관한 처리로 파일정보를 읽기위해 이런 처리가 필요

	int cnt; 
	while ((cnt = read(fd, buf, BUF_SIZE)) > 0) write(asock, buf, cnt); //mime에서 body에 해당하는 local_uri로 아무 값이나 입력이 가능
}

