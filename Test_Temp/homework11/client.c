#include <sys/socket.h>  /* 소켓 관련 함수 */
#include <arpa/inet.h>   /* 소켓 지원을 위한 각종 함수 */
#include <sys/stat.h>
#include <stdio.h>      /* 표준 입출력 관련 */
#include <string.h>     /* 문자열 관련 */
#include <unistd.h>     /* 각종 시스템 함수 */

#define MAXLINE    1024

#define MAXFDS 64

int main(int argc, char **argv)
{
    struct sockaddr_in serveraddr;
    int server_sockfd;
    int client_len;
    char buf[MAXLINE];

    int retval;
    fd_set read_fds;


    if ((server_sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("socket error :");
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

    while(1) {
        
        memset(buf, 0x00, MAXLINE);
        //select()를 위한 fd_set 변수 선언 및 초기화
        FD_ZERO(&read_fds);
        FD_SET(0, &read_fds);
        FD_SET(server_sockfd, &read_fds);

        //새로운 수식을 입력하면 다시 서버로 전송 구현을 위해 select()함수를 사용해야함
        retval = select(MAXFDS, &read_fds, 0, 0, NULL);
        
        if(retval == -1) {
            perror("select error : ");
            return 1;
        }
        else if(retval == 0) {
            continue;
        }
        else if(FD_ISSET(STDIN_FILENO, &read_fds)) { //사용자가 새로운 수식과 스트링을 입력했을 경우
            //수식, 스트링 입력받기    
            if( read(STDIN_FILENO, buf, MAXLINE) <= 0 ) {
                perror("read_fds STDIN_FILENO error : ");
                return 1;
            }
            write(server_sockfd, buf, strlen(buf)); // 서버로 전송
        }
        else if(FD_ISSET(server_sockfd, &read_fds)) {// 서버에서 전송한 데이터가 있을 경우

            if( read(server_sockfd, buf, MAXLINE) <= 0 ) {
                perror("read_fds server_sockfd error : ");
                return 1;
            }
            
            if (strncmp(buf, "quit", 4) == 0) {
                return 0;
            }
            printf("%s", buf); // 서버에서 전송한 데이터 출력

        }

    }

    close(server_sockfd);
    return 0;
}
