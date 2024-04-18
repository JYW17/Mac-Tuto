#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

#define MAXLINE 1024
#define PORTNUM 3600

int main(int argc, char **argv)
{
	int listen_fd, client_fd;
	pid_t pid;
	socklen_t addrlen;
	int readn;
	char buf[MAXLINE];
	struct sockaddr_in client_addr, server_addr;

	if( (listen_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		return 1;
	}
	memset((void *)&server_addr, 0x00, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	server_addr.sin_port = htons(PORTNUM);

	if(bind(listen_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) ==-1)
	{
		perror("bind error");
		return 1;
	}
	if(listen(listen_fd, 5) == -1)
	{
		perror("listen error");
		return 1;
	}

	signal(SIGCHLD, SIG_IGN);
	while(1)
	{
		addrlen = sizeof(client_addr);
		client_fd = accept(listen_fd,
			(struct sockaddr *)&client_addr, &addrlen);
		if(client_fd == -1)
		{
			printf("accept error\n");
			break;
		}
		pid = fork();
		if(pid == 0)
		{
			close(listen_fd);

			char result[MAXLINE * 5];
			int cycle = 0;

			while((readn = read(client_fd, buf, MAXLINE)) > 0)
			{
				cycle++; // 몇 번째 데이터인지 카운트
				buf[strlen(buf) - 1] = '\0'; // 개행 문자 제거

				// 클라이언트의 IP 주소와 Port 번호, 몇 번째 데이터인지, 데이터 내용 출력
				printf("%s Client's Port: %d - No.%d Read Data: %s\n",
						inet_ntoa(client_addr.sin_addr),
						client_addr.sin_port,
						cycle,
						buf);
				
				if(strncmp(buf, "quit", 4) == 0) // "quit" 문자열을 입력 받으면 break
				{
					printf("%s Cliet's Port %d - quit\n",
							inet_ntoa(client_addr.sin_addr),
							client_addr.sin_port);
					break;
				}

				strcat(result, buf); // 문자열 이어 붙이기
				strcat(result, " "); // 문자열 이어 붙이기

				memset(buf, 0x00, MAXLINE);
			}
			
			result[strlen(result) - 1] = '\0'; // 마지막 공백 문자 제거
			printf("%s\n", result); // 이어진 문자열 출력
			write(client_fd, result, strlen(result)); // 이어진 문자열 client에 전송
			sleep(10); // client가 데이터를 받을 수 있도록 10초간 sleep

			close(client_fd);
			return 0;
		}
		else if( pid > 0)
			close(client_fd);
	}
	return 0;
}