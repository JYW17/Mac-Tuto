#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINE 1024
#define PORTNUM 3600
#define SOCK_SETSIZE 1021

struct cal_data {
    int left_num;
    int right_num;
    char op;
    char user_string[100];
    int result;
    int error;
};

int main(int argc, char **argv) {

	int listen_fd, client_fd;
	socklen_t addrlen;
	int fd_num;
	int maxfd = 0;
	int sockfd, send_sockfd;
	int i = 0, j = 0;
	char buf[MAXLINE];
	fd_set readfds, allfds;

	char *token;
	struct cal_data cal[3 + SOCK_SETSIZE];
	int cal_size = sizeof(struct cal_data);
	char send_buf[MAXLINE + 100*1021];
	char strings[3 + SOCK_SETSIZE][100];

	struct sockaddr_in server_addr, client_addr;

	if((listen_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		perror("socket error");
		return 1;
	}

	memset((void *)&server_addr, 0x00, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	server_addr.sin_port = htons(PORTNUM);
	
	if(bind(listen_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
		perror("bind error");
		return 1;
	}   
	
	if(listen(listen_fd, 5) == -1) 	{
		perror("listen error");
		return 1;
	}   
	
	FD_ZERO(&readfds);
	FD_SET(listen_fd, &readfds);

	maxfd = listen_fd;

	while(1) {
		
		allfds = readfds;
		printf("Select Wait maxfd:%d\n", maxfd);
		fd_num = select(maxfd + 1 , &allfds, (fd_set *)0, (fd_set *)0, NULL);

		if (fd_num == -1) {
			perror("select error");
			return 1;
		}

		//연결할 클라이언트가 있을 때
		if (FD_ISSET(listen_fd, &allfds)){

			addrlen = sizeof(client_addr);
			client_fd = accept(listen_fd, (struct sockaddr *)&client_addr, &addrlen);

			FD_SET(client_fd, &readfds);

			if (client_fd > maxfd) {
				maxfd = client_fd;
			}

			printf("Accept %d\n", client_fd);
			continue; //다시 select()로 돌아감
		}

		//각 sockfd 별로 클라이언트로부터 데이터를 받음
		for (i = 0; i <= maxfd; i++) {
			
			sockfd = i;
			if (FD_ISSET(sockfd, &allfds)) {
				
				memset(buf, 0x00, MAXLINE);
				memset(&cal, 0x00, cal_size);
				
				if (read(sockfd, buf, MAXLINE) <= 0) {
					printf("readn is less than 0 close %d sockfd\n", sockfd);
					close(sockfd);
					FD_CLR(sockfd, &readfds);
				}
				
				if (strncmp(buf, "quit", 4) == 0) {
                    write(sockfd, "quit\n", 5);
					printf("sockfd:%d quit\n", sockfd);
					memset(strings[sockfd], 0x00, sizeof(strings[sockfd]));  // strings[sockfd]을 비움
					close(sockfd);
					FD_CLR(sockfd, &readfds);
					continue;
				}

				printf("Sockfd %d Read : %s", sockfd, buf);
				

				//문자열 파싱
				token = strtok(buf, " \t\n");
                if (token != NULL) cal[sockfd].left_num = atoi(token);
                token = strtok(NULL, " \t\n");
                if (token != NULL) cal[sockfd].right_num = atoi(token);
                token = strtok(NULL, " \t\n");
                if (token != NULL) cal[sockfd].op = token[0];
                token = strtok(NULL, " \t\n");
                if (token != NULL) strcpy(cal[sockfd].user_string, token);

				//quit 입력시 종료
				if (strncmp(cal[sockfd].user_string, "quit", 4) == 0) {
                    write(sockfd, "quit\n", 5);
					printf("sockfd:%d quit\n", sockfd);
					memset(strings[sockfd], 0x00, sizeof(strings[sockfd]));  // strings[sockfd]을 비움
					close(sockfd);
					FD_CLR(sockfd, &readfds);
                }

				//strings[sockfd]에 클라이언트의 string을 저장, 이후에 이어붙힐 예정
				strcpy(strings[sockfd], cal[sockfd].user_string);

				switch(cal[sockfd].op) {
                    case '+':
                        cal[sockfd].result = cal[sockfd].left_num + cal[sockfd].right_num;
                        break;
                    case '-':
                        cal[sockfd].result = cal[sockfd].left_num - cal[sockfd].right_num;
                        break;
                    case 'x':
                        cal[sockfd].result = cal[sockfd].left_num * cal[sockfd].right_num;
                        break;
                    case '/':
                        if (cal[sockfd].right_num == 0) {
                            cal[sockfd].error = 1;
                        } else {
                            cal[sockfd].result = cal[sockfd].left_num / cal[sockfd].right_num;
                        }
                        break;
                    default:
                        cal[sockfd].error = -1;
                        break;
                }

				for (j = 4; j <= maxfd; j++){

					send_sockfd = j;
					if (cal[send_sockfd].user_string[0] == '\0') continue;

					memset(send_buf, 0x00, MAXLINE + 100*1021);

					if (cal[send_sockfd].error == 0) {
						sprintf(send_buf, "%d %c %d = %d ", cal[send_sockfd].left_num, cal[send_sockfd].op, cal[send_sockfd].right_num, cal[send_sockfd].result);
					} else if (cal[send_sockfd].error == 1) {
						sprintf(send_buf, "0으로 나눌 수 없습니다.\n");
					} else {
						sprintf(send_buf, "잘못된 수식입니다.\n");
					}

					//클라이언트들의 string을 이어붙힘
					for (i = 0; i <= maxfd; i++) {
						if (strlen(strings[i]) == 0) continue; //비어있는 strings[i]는 건너뜀
						printf("strings[%d] : %s\n", i, strings[i]);
						strcat(send_buf, strings[i]);
						strcat(send_buf, " ");
					}
					strcat(send_buf, "\n");

					printf("send_sockfd : %d\n", send_sockfd);
					printf("send_buf : %s", send_buf);
					write(send_sockfd, send_buf, sizeof(send_buf));

				}
				
				if (--fd_num <= 0)
					break;
			}
		}
	}
}
