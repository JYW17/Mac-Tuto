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
#include <pthread.h>

#define MAXLINE 1024
#define PORTNUM 3600
#define LOOP_TIME 10
#define MAXMUTEX 256

struct cal_data {
    int left_num;
    int right_num;
    char op;
    char user_string[100];
    int result;
    int error;
    struct tm time_data;
};


time_t now_time;
struct tm *current_time;
int worker_thread_num = 0;
pthread_mutex_t m_lock[MAXMUTEX];
pthread_cond_t cond[MAXMUTEX];
struct cal_data shared_data[MAXMUTEX];


// void * worker_thread(void *data) {
    
//     int sockfd = *((int *) data);

//     pthread_t producer_thread, consumer_thread;

//     // mutex init
//     // cond_init
    

// }

void * producer_thread(void *data) {

    int thread_num = worker_thread_num;
    time_t now_time;
    struct tm *current_time;
    int flag = 0; // 1이면 데이터가 들어온 상태
    char *token;


    int client_fd = *((int *) data);
    int readn, retval;
    socklen_t addrlen;
    char buf[MAXLINE];
    struct sockaddr_in client_addr, server_addr;
    addrlen = sizeof(client_addr);

    memset(buf, 0x00, MAXLINE);

    getpeername(client_fd, (struct sockaddr *)&client_addr, &addrlen);

    fd_set read_fds;
    struct timeval timeout;

    int cal_data_size = sizeof(struct cal_data);


    printf("Producer Thread-%s thread_num:%d\n", inet_ntoa(client_addr.sin_addr), thread_num);

    while(1){

        memset(buf, 0x00, MAXLINE);
        FD_ZERO(&read_fds);
        FD_SET(client_fd, &read_fds);

        timeout.tv_sec = 10;
        timeout.tv_usec = 0;

        retval = select(64, &read_fds, NULL, NULL, &timeout);

        if (retval == -1) {
            perror("select failed : ");
            return NULL;
        } else if (retval == 0) {
            
            if (flag == 0) {
                continue;
            }

            time(&now_time);
            current_time = localtime(&now_time);
            shared_data[thread_num].time_data = *current_time;

            // printf("timeout.tv_sec : %ld\n", timeout.tv_sec);
            // printf("timeout.tv_usec : %d\n", timeout.tv_usec);

            pthread_cond_signal(&cond[thread_num]);
        } else {
            
            if (FD_ISSET(client_fd, &read_fds)) {

                // memset(shared_data[thread_num], 0x00, sizeof(int));
                memset(&shared_data[thread_num], 0x00, cal_data_size);

                readn = read(client_fd, buf, MAXLINE);

                if (readn < 0) {
                    printf("Producer read error\n");
                    return NULL;
                }

                if (flag == 0) flag = 1;

                printf("Producer read : %s\n", buf);

                token = strtok(buf, " \t\n");
                if (token != NULL) shared_data[thread_num].left_num = atoi(token);
                token = strtok(NULL, " \t\n");
                if (token != NULL) shared_data[thread_num].right_num = atoi(token);
                token = strtok(NULL, " \t\n");
                if (token != NULL) shared_data[thread_num].op = token[0];
                token = strtok(NULL, " \t\n");
                if (token != NULL) strcpy(shared_data[thread_num].user_string, token);

                if (strncmp(shared_data[thread_num].user_string, "quit", 4) == 0) {
                    printf("Producer quit\n");
                    pthread_cond_signal(&cond[thread_num]);
                    return NULL;
                }

                switch(shared_data[thread_num].op) {
                    case '+':
                        shared_data[thread_num].result = shared_data[thread_num].left_num + shared_data[thread_num].right_num;
                        break;
                    case '-':
                        shared_data[thread_num].result = shared_data[thread_num].left_num - shared_data[thread_num].right_num;
                        break;
                    case 'x':
                        shared_data[thread_num].result = shared_data[thread_num].left_num * shared_data[thread_num].right_num;
                        break;
                    case '/':
                        if (shared_data[thread_num].right_num == 0) {
                            shared_data[thread_num].error = 1;
                        } else {
                            shared_data[thread_num].result = shared_data[thread_num].left_num / shared_data[thread_num].right_num;
                        }
                        break;
                    default:
                        shared_data[thread_num].error = -1;
                        break;
                }

                time(&now_time);
                current_time = localtime(&now_time);
                shared_data[thread_num].time_data = *current_time;

                pthread_cond_signal(&cond[thread_num]);

            }

        }

    }

    close(client_fd);
    printf("Producer Thread-%s thread_num:%d quit\n", inet_ntoa(client_addr.sin_addr), thread_num);
    return 0;
}

void * consumer_thread(void *data) {

    int thread_num = worker_thread_num;

    int client_fd = *((int *) data);
    int readn;
    socklen_t addrlen;
    char buf[MAXLINE];
    struct sockaddr_in client_addr, server_addr;
    addrlen = sizeof(client_addr);
    char time_string[100];


    memset(buf, 0x00, MAXLINE);
    memset(time_string, 0x00, 100);

    getpeername(client_fd, (struct sockaddr *)&client_addr, &addrlen);

    printf("Consumer Thread-%s thread_num:%d\n", inet_ntoa(client_addr.sin_addr), thread_num);

    while(1) {
        memset(buf, 0x00, MAXLINE);
        memset(time_string, 0x00, 100);

        pthread_mutex_lock(&m_lock[thread_num]);
        pthread_cond_wait(&cond[thread_num], &m_lock[thread_num]);

        if (strncmp(shared_data[thread_num].user_string, "quit", 4) == 0) {
            printf("Consumer quit\n");
            write(client_fd, "quit", 5);
            return NULL;
        }


        if (shared_data[thread_num].error == 0) {
            sprintf(buf, "%d %c %d = %d ", shared_data[thread_num].left_num, shared_data[thread_num].op, shared_data[thread_num].right_num, shared_data[thread_num].result);
        } else if (shared_data[thread_num].error == 1) {
            sprintf(buf, "0으로 나눌 수 없습니다.\n");
        } else {
            sprintf(buf, "잘못된 수식입니다.\n");
        }

        strftime(time_string, 100, "%Y-%m-%d %H:%M:%S\n", &shared_data[thread_num].time_data);
        strcat(buf, time_string);

        write(client_fd, buf, strlen(buf));

        pthread_mutex_unlock(&m_lock[thread_num]);
        
    }

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

    // 스레드 관련
    pthread_t thread_id;

   if ( (listen_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0 ) {
      return 1;
   }

   memset((void *)&server_addr, 0x00, sizeof(server_addr));
   server_addr.sin_family = AF_INET;
   server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
   server_addr.sin_port = htons(PORTNUM);

   if (bind(listen_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
      perror("bind error");
      return 1;
   }
   if (listen(listen_fd, 5) == -1) {
      perror("listen error");
      return 1;
   }

   
    

    while(1) {
            
        addrlen = sizeof(client_addr);
        client_fd = accept(listen_fd,
            (struct sockaddr *)&client_addr, &addrlen);
        if (client_fd == -1) {
            printf("accept error\n");
            break;
        }

        worker_thread_num++;

        pthread_mutex_init(&m_lock[worker_thread_num], NULL);
        pthread_cond_init(&cond[worker_thread_num], NULL);

        pthread_create(&thread_id, NULL, producer_thread, (void *) &client_fd);
        pthread_detach(thread_id);
        pthread_create(&thread_id, NULL, consumer_thread, (void *) &client_fd);
        pthread_detach(thread_id);
    
    }
    
    return 0;
}
