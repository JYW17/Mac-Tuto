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
#include <time.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/ipc.h>

#define MAXLINE 1024
#define PORTNUM 3600
#define LOOP_TIME 10

struct cal_data {
    int left_num;
    int right_num;
    char op;
    char user_string[100];
    int result;
    int error;
    struct tm time_data;
};

// union semun {
//     int val;
// };

// 공유 메모리 및 세마포어 관련
int shmid, semid;
void *shmaddr = NULL;
struct cal_data *shm_cal;
time_t now_time;
struct tm *current_time;
struct sembuf semopen = {0, -1, SEM_UNDO};
struct sembuf semclose = {0, 1, SEM_UNDO};

void loopTime(int signo){
    time(&now_time);
    current_time = localtime(&now_time);

    shm_cal->time_data = *current_time;
    if (semop(semid, &semclose, 1) == -1) {
        perror("loopTime semop failed : ");
        exit(0);
    }

    alarm(LOOP_TIME);
}

int main(int argc, char **argv)
{
    // 소켓 관련
	int listen_fd, client_fd;
	pid_t pid;
	socklen_t addrlen;
	int readn;
	char buf[MAXLINE];
	struct sockaddr_in client_addr, server_addr;

    int shm_keys = 1000;
    int sem_keys = 5000;

    union semun sem_union;

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

        // 공유 메모리 생성
        shmid = shmget((key_t)shm_keys, sizeof(struct cal_data), 0666|IPC_CREAT);
        if (shmid == -1) {
            perror("shmget failed : ");
            exit(0);
        }

        // 세마포어 생성
        semid = semget((key_t)sem_keys, 1, 0666|IPC_CREAT); // Producer와 Consumer를 위한 1개의 세마포어
        if (semid == -1) {
            perror("semget failed : ");
            exit(0);
        }

        // 세마포어 초기화
        sem_union.val = 0;
        if (semctl(semid, 0, SETVAL, sem_union) == -1) {
            perror("semctl failed : ");
            exit(0);
        }
        
		pid = fork();
		if(pid == 0) {// Producer와 Consumer를 가지는 자식 프로세스
			close(listen_fd);

            pid = fork(); // 부모 자식 개념이 아닌 Producer와 Consumer 개념으로 자식 프로세스 생성
            if (pid == 0) { // Producer client로부터 데이터를 받고 계산 후 공유 메모리에 저장
                printf("Producer process-%s pid:%d\n", inet_ntoa(client_addr.sin_addr), getpid());
                struct cal_data local_data;
                char *token;

                // 공유 메모리 연결
                shmaddr = shmat(shmid, (void *)0, 0);
                if (shmaddr == (char *)-1) {
                    perror("shmat failed : ");
                    exit(0);
                }
                shm_cal = (struct cal_data *)shmaddr;

                signal(SIGALRM, loopTime); // 3초마다 현재 시간 출력

                while(1){
                    memset(buf, 0x00, MAXLINE);
                    readn = read(client_fd, buf, MAXLINE);
                    if (readn < 0) {
                        printf("Produver read error\n");
                    }

                    printf("Producer read : %s\n", buf);
                    token = strtok(buf, " \t\n");
                    if (token != NULL) local_data.left_num = atoi(token);
                    token = strtok(NULL, " \t\n");
                    if (token != NULL) local_data.right_num = atoi(token);
                    token = strtok(NULL, " \t\n");
                    if (token != NULL) local_data.op = token[0];
                    token = strtok(NULL, " \t\n");
                    if (token != NULL) strcpy(local_data.user_string, token);

                    // quit이 입력되면 종료
                    if(strncmp(local_data.user_string, "quit", 4) == 0) {
                        printf("Producer quit\n");
                        strcpy(shm_cal->user_string, "quit"); // Consumer에게 종료를 알리기 위해 공유 메모리에 quit 저장
                        if (semop(semid, &semclose, 1) == -1) {
                            perror("semop failed : ");
                            exit(0);
                        }
                        return 0;
                    }

                    // 계산 후 공유 메모리에 저장
                    local_data.result = 0;
                    local_data.error = 0;
                    switch(local_data.op) {
                        case '+':
                            local_data.result = local_data.left_num + local_data.right_num;
                            break;
                        case '-':
                            local_data.result = local_data.left_num - local_data.right_num;
                            break;
                        case 'x':
                            local_data.result = local_data.left_num * local_data.right_num;
                            break;
                        case '/':
                            if(local_data.right_num == 0) {
                                local_data.error = 1;
                                break;
                            }
                            local_data.result = local_data.left_num / local_data.right_num;
                            break;
                        default:
                            local_data.error = -1;
                            break;
                    }

                    time(&now_time);
                    struct tm *current_time = localtime(&now_time);
                    local_data.time_data = *current_time;

                    shm_cal->left_num = local_data.left_num;
                    shm_cal->right_num = local_data.right_num;
                    shm_cal->op = local_data.op;
                    strcpy(shm_cal->user_string, local_data.user_string);
                    shm_cal->result = local_data.result;
                    shm_cal->error = local_data.error;
                    shm_cal->time_data = local_data.time_data;

                    if(semop(semid, &semclose, 1) == -1) {
                        perror("After shm_cal write semop_semclose failed : ");
                        exit(0);
                    }

                    alarm(LOOP_TIME); // 3초마다 현재 시간 출력

                }

                close(client_fd);
                return 0;

            } else { // Consumer 공유 메모리로부터 데이터를 읽고 일정 시간마다 client에게 데이터 전송
                printf("Consumer process-%s pid:%d\n", inet_ntoa(client_addr.sin_addr), getpid());
                struct cal_data local_data;
                char time_string[100];
                
                shmaddr = shmat(shmid, (void *)0, 0);
                if (shmaddr == (char *)-1) {
                    perror("Consumer shmat failed : ");
                    exit(0);
                }

                shm_cal = (struct cal_data *)shmaddr;



                while(1){
                    memset(buf, 0x00, MAXLINE);
                    memset(time_string, 0x00, 100);

                    if (semop(semid, &semopen, 1) == -1) {
                        perror("semop_semopen failed : ");
                        exit(0);
                    }
                    
                    if (strncmp(shm_cal->user_string, "quit", 4) == 0) {
                        printf("Consumer quit\n");
                        write(client_fd, shm_cal->user_string, strlen(shm_cal->user_string));
                        return 0;
                    }

                    local_data.left_num = shm_cal->left_num;
                    local_data.right_num = shm_cal->right_num;
                    local_data.op = shm_cal->op;
                    strcpy(local_data.user_string, shm_cal->user_string);
                    local_data.result = shm_cal->result;
                    local_data.error = shm_cal->error;
                    local_data.time_data = shm_cal->time_data;

                    if (local_data.error == 0) {
                        sprintf(buf, "%d %c %d = %d ", local_data.left_num, local_data.op, local_data.right_num, local_data.result);
                    } else if (local_data.error == 1) {
                        sprintf(buf, "0으로 나눌 수 없습니다.\n");
                    } else {
                        sprintf(buf, "잘못된 수식입니다.\n");
                    }

                    strftime(time_string, 100, "%Y-%m-%d %H:%M:%S\n", &local_data.time_data);
                    strcat(buf, time_string);

                    write(client_fd, buf, strlen(buf));

                }

            }
			return 0; // 클라이언트와 통신하던 자식 프로세스 종료
		}
		else if (pid > 0){ // 부모 프로세스
			close(client_fd); // 새 클라이언트를 위해 소켓 닫기
            // 새 클라이언트를 위해 공유 메모리 및 세마포어 키값 증가
            shm_keys++;
            sem_keys++;
        }
	}
	return 0;
}
