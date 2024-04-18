#include <sys/socket.h>  /* 소켓 관련 함수 */
#include <arpa/inet.h>   /* 소켓 지원을 위한 각종 함수 */
#include <sys/stat.h>
#include <stdio.h>      /* 표준 입출력 관련 */
#include <string.h>     /* 문자열 관련 */
#include <unistd.h>     /* 각종 시스템 함수 */

#define MAXLINE    1024

int main(int argc, char **argv)
{
    struct sockaddr_in serveraddr;
    int server_sockfd;
    int client_len;
    int readn;
    char buf[MAXLINE];
    char send_buf[MAXLINE + 100*1021];

    int retval;
    fd_set read_fds;

    if ((server_sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) 
    {
        perror("error :");
        return 1;
    }

    /* 연결요청할 서버의 주소와 포트번호 프로토콜등을 지정한다. */
    server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serveraddr.sin_port = htons(3600);

    client_len = sizeof(serveraddr);

    /* 서버에 연결을 시도한다. */
    if (connect(server_sockfd, (struct sockaddr *)&serveraddr, client_len)  == -1)
    {
        perror("connect error :");
        return 1;
    }

    while(1) 
    {
        memset(buf, 0x00, MAXLINE);

        FD_ZERO(&read_fds);
        FD_SET(0, &read_fds);
        FD_SET(server_sockfd, &read_fds);

        retval = select(64, &read_fds, 0, 0, NULL);

        if(retval == -1) {
            perror("select error : ");
            return 1;
        } else if(retval == 0) {
            continue;

        } else if (FD_ISSET(server_sockfd, &read_fds)) {
            /* 서버로 부터 데이터를 읽는다. */
            if (read(server_sockfd, send_buf, MAXLINE + 100*1021) <= 0) {
                perror("read error : ");
                return 1;
            }

            if (strncmp(send_buf, "quit", 4) == 0) {
                printf("Good bye...\n");
                break;
            }

            printf("%s", send_buf);
            memset(send_buf, 0x00, MAXLINE);

        } else if (FD_ISSET(STDIN_FILENO, &read_fds)) {
            /* 키보드 입력을 기다린다. */
            if (read(STDIN_FILENO, buf, MAXLINE) <= 0) 
            {
                perror("read error : ");
                return 1;
            }
            /* 입력 받은 데이터를 서버로 전송한다. */
            if (write(server_sockfd, buf, MAXLINE) <= 0) 
            {
                perror("write error : ");
                return 1;
            }
        }
    }
    
    close(server_sockfd);
    return 0;
}
