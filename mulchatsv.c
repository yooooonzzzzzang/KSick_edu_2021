#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/epoll.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/tcp.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <errno.h>

#define EPOLL_SIZE 60
#define EPOLL_EVENT_SIZE 100
#define OPENPORT 9000

int main(int argc,char**argv)
{
	struct epoll_event *events;
	struct epoll_event ev;
	struct sockaddr_in addr, clientaddr;
	int clilen;
	int sfd, efd, cfd;	
	int i,j;	//for 문 
	int max_got_events;
	int result;
	int readn;
	int sendflags=0;
	char buf_in[256]={'\0'};//버퍼
	int count =0;
	//epoll 소켓 생성
	if((efd=epoll_create(EPOLL_EVENT_SIZE))<0)
	{
		perror("epoll_create (1) error");
		return -1;
	}
	//init poll
	events = (struct epoll_event *)malloc(sizeof(*events)*EPOLL_SIZE);
	if(events<0)
	{
		printf("epoll_create()fail!\n");
		return -1;
	}


	//서버소켓 생성
	clilen = sizeof(clientaddr);
	sfd = socket(AF_INET,SOCK_STREAM,0);//인터넷으로 연결된 프로세스 간에 통신
	if(sfd==-1)	//실패시
	{
		perror("socket error: ");
		close (sfd);
		return -1;
	}
	//소켓 정보 넣기
	addr.sin_family =AF_INET;	//사용하는 주소체계
	addr.sin_port =htons(OPENPORT);	//16비트 포트번호 배정:네트워크 바이트 순서 형태 htons - short형 호스트 바이트 순서를 네트워크 바이트 순서로 변경
	addr.sin_addr.s_addr = htonl(INADDR_ANY); //long 형으로 된 ip주소: 
	//INADDR_ANY : ip주소를 자동으로 찾아서 대입해줌
	//
	//bind 로 소켓에 ip주소와 포트 번호를 연결 -> sfd 에 addr연결
	if(bind(sfd,(struct sockaddr*)&addr, sizeof(addr))==-1)
	{
		close(sfd);
		return -2;
	}

	//sfd 소켓으로 들어오는 클라이언트 요청 기다린다 5는 클라이언트 요구가 대기하는 큐의 크기
	if(listen(sfd,5)==-1){
		perror("listen failed");
		return 1;
	}
	
	//서버 시작, epoll 이벤트 설정 및 컨트롤 함수로 활성화
	printf("Running Server port %d\n", OPENPORT);
	ev.events = EPOLLIN;	//수신할 데이터가 있다.
	ev.data.fd = sfd;
	result = epoll_ctl(efd, EPOLL_CTL_ADD, sfd, &ev); //fd를 epoll에 등록
	if(result<0)
	{
		perror("epoll_ctl error");
		return 1;
	}
	
	//서버 실제 루트
	while(1)
	{	
		//epoll 이벤트 대기(클라이언트의 반응(접속 or send)감지)
		max_got_events = epoll_wait(efd, events,EPOLL_SIZE ,-1);

		//epoll 이벤트 받은 만큼의 숫자만큼 for
		for(i=0; i<max_got_events; i++)
			// 이벤트 들어온 소켓이 연결 요청이면 
			if(events[i].data.fd == sfd)
			{
				cfd = accept(sfd, (struct sockaddr*)&clientaddr, &clilen);
				if(cfd<0)
				{
					perror("Accept error");
					return -1;
				}
				ev.events = EPOLLIN;
				ev.data.fd =cfd;
				epoll_ctl(efd, EPOLL_CTL_ADD,cfd, &ev);

				printf("Accepted socker : %d\n", cfd);
				count++;
			}
			else
			{
				 cfd = events[i].data.fd;

				 memset(buf_in, 0x00, 256);
				 readn = read(cfd, buf_in, 255);

				 if(readn<=0)
				 {
					 epoll_ctl(efd, EPOLL_CTL_DEL, cfd, &ev);
					 close(cfd);
					 printf("Close fd %d\n", cfd);

					 count--;
				 }
				 else
				 {
					 for(j=5; i<count+5; j++)
					 {
						 if(cfd!=j)
							 send(j,buf_in, strlen(buf_in), sendflags);
					 }
				 }
			}
	}
}
return 1;
}
