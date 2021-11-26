#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <tchar.h>

WSADATA wsaData;
SOCKET sock0, sockw;
struct sockaddr_in addr;
struct sockaddr_in client;
#define PORT_NUM 8000


int getAddrHost(void){
	int i;
	HOSTENT *lpHost;
	IN_ADDR inaddr;
	char szBuf[256], szIP[16];

	if(WSAStartup(MAKEWORD(1,1) , &wsaData) != 0) {
		printf("WSAStartup Error\n");
		return -1;
	}

	gethostname(szBuf, (int)sizeof(szBuf));

	lpHost = gethostbyname(szBuf);

	for(i=0; lpHost -> h_addr_list[i]; i++){
		memcpy(&inaddr, lpHost->h_addr_list[i], 4);
	}
	strcpy(szIP, inet_ntoa(inaddr));
	printf("build server : http://%s:%d\n", szIP, PORT_NUM);

	WSACleanup();

	return 0;
}

char *get_name(char *name){
}

int main()
{
	int len;
	int n;
	int sockaddr_in_size = sizeof(struct sockaddr_in);
	int recv_len =0;
	unsigned char buf[1024];
	unsigned char path[1024];
	unsigned char html[1024];

	if(getAddrHost() != 0){
		printf("get IP address failed");
		getch();
		return -1;
	}

	if(WSAStartup(MAKEWORD(2,0), &wsaData))
	{
		puts("reset winsock failed");
		getch();
		return -1;
	}

	sock0 = socket(AF_INET, SOCK_STREAM, 0);
	if(sock0 == INVALID_SOCKET)
	{
		printf("socket : %d\n", WSAGetLastError());
		getch();
		return -1;
	}

	addr.sin_family = AF_INET;
	addr.sin_port = htons(PORT_NUM);
	addr.sin_addr.S_un.S_addr = INADDR_ANY;

	if(bind(sock0, (struct sockaddr *)&addr, sizeof(addr)) !+ 0)
	{
		printf("bind : %d\n", WSAGetLastError());
		getch();
		return -1;
	}

	if(listen(sock0, 5) != 0)
	{
		printf("listen : %d\n", WSAGetLastError());
		getch();
		return -1;
	}

	while(1)
	{
		len= sizeof(client);
		sockw = accept(sock0, (struct sockaddr *)&client, &len);
		if(sockw == INVALID_SOCKET)
		{
			printf("accept : %d\n", WSAGetLastError());
			break;
		}

		memset(path, 0, 1024);
		memset(html, 0,1024);
		
		recv_len = recvfrom(sockw, buf, 1024, 0, (struct sockaddr *)&client, &sockaddr_in_size);
		buf[recv_len -1] = 0;
		if(buf[0] == '\0')
			strcpy(buf, NULL);

		pritnf("%s \n", buf);

		for(int i= 0; i<strlen(buf); i++){
			printf("%d\n", i);
			if(buf[i] == 'G' && buf[i +1] == 'E'






if(send(sock, index.html, strlen(index.html), 0)<1)
{
	printf("send : %d\n", WSAGetLastError());
	break;
}
