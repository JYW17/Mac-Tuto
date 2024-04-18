#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAXLINE 1024

int main() {
    int fd[2]; // 파이프 디스크립터 배열

    if (pipe(fd) == -1) {
        perror("pipe error");
        exit(EXIT_FAILURE);
    }

    pid_t pid;

    for (int i = 0; i < 3; i++) {
        pid = fork();

        if (pid == -1) {
            perror("fork error");
            exit(EXIT_FAILURE);
        } else if (pid == 0) { // 자식 프로세스
            close(fd[0]); // 자식은 읽지 않으므로 읽기 파이프 닫기
            // 자식이 부모에게 쓰기
            char message[MAXLINE];
            sprintf(message, "Hello from Child %d", i);
            write(fd[1], message, strlen(message));
            close(fd[1]); // 쓰기 파이프 닫기
            exit(EXIT_SUCCESS);
        }
    }

    // 부모 프로세스
    close(fd[1]); // 부모는 쓰지 않으므로 쓰기 파이프 닫기

    for (int i = 0; i < 3; i++) {
        char buffer[MAXLINE];
        read(fd[0], buffer, sizeof(buffer)); // 부모가 읽기
        printf("Parent received: %s\n", buffer);
    }

    close(fd[0]); // 읽기 파이프 닫기

    return 0;
}
