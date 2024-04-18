/*
matrixSum.c
행렬의 덧셈을 통한 메모리 접근 시간 비교
시스템 프로그래밍 1분반 
32194459 주영운 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>

#define N 10000

// n x n 행렬을 생성하고 0부터 99까지의 난수로 채움
void generateRandomMatrix(int n, int matrix[][n]) {
    
    // 시드값을 현재 시간으로 설정하여 매번 다른 난수 생성
    int i,j;
    srand(time(NULL));
    // 행렬에 0부터 99까지의 난수 채우기
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            matrix[i][j] = rand() % 100; // 0부터 99까지의 난수 생성
        }
    }
}

// 행렬의 덧셈 행 기준 연산
void matrixSum1(int n, int matrix1[][n], int matrix2[][n], int sum[][n]) {
    // 행렬의 덧셈
    // 시작 시간 측정
    int i,j;
    struct timeval start, end, gap;
    gettimeofday(&start, NULL);

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            sum[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    // 종료 시간 측정
    gettimeofday(&end, NULL);

    // 경과 시간 출력
    gap.tv_sec = end.tv_sec - start.tv_sec;
    gap.tv_usec = end.tv_usec - start.tv_usec;
    if (gap.tv_usec < 0) {
        gap.tv_sec = gap.tv_sec - 1;
        gap.tv_usec += 1000000;
    }
    printf("행 기준 연산 경과 시간: %ld.%06ld\n", gap.tv_sec, gap.tv_usec);

}

// 행렬의 곱셈 열 기준 연산
void matrixSum2(int n, int matrix1[][n], int matrix2[][n], int sum[][n]) {
    // 행렬의 덧셈
    // 시작 시간 측정
    int i,j;
    struct timeval start, end, gap;
    gettimeofday(&start, NULL);
    for (j = 0; j < n; j++) {
        for (i = 0; i < n; i++) {
            sum[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    // 종료 시간 측정
    gettimeofday(&end, NULL);

    // 경과 시간 출력
    gap.tv_sec = end.tv_sec - start.tv_sec;
    gap.tv_usec = end.tv_usec - start.tv_usec;
    if (gap.tv_usec < 0) {
        gap.tv_sec = gap.tv_sec - 1;
        gap.tv_usec += 1000000;
    }
    printf("열 기준 연산 경과 시간: %ld.%06ld\n", gap.tv_sec, gap.tv_usec);
}

// fork를 이용한 행렬의 덧셈 - 열 기준
void matrixSum3(int n, int matrix1[][n], int matrix2[][n], int sum[][n]) {
    // 행렬의 덧셈
    // 시작 시간 측정
    int i,j;
    struct timeval start, end, gap;
    gettimeofday(&start, NULL);
    pid_t pid;
    pid = fork();

    if(pid == 0){
        for (j = 0; j < n/2; j++) { // 열 기준으로 나누기
            for (i = 0; i < n; i++) {
                sum[i][j] = matrix1[i][j] + matrix2[i][j];
            }
        }
    }
    else{
        for (j = n/2; j < n; j++) {
            for (i = 0; i < n; i++) {
                sum[i][j] = matrix1[i][j] + matrix2[i][j];
            }
        }
        wait(NULL);
        // 종료 시간 측정
        gettimeofday(&end, NULL);

        // 경과 시간 출력
        gap.tv_sec = end.tv_sec - start.tv_sec;
        gap.tv_usec = end.tv_usec - start.tv_usec;
        if (gap.tv_usec < 0) {
            gap.tv_sec = gap.tv_sec - 1;
            gap.tv_usec += 1000000;
        }
        printf("matrixSum3 경과 시간: %ld.%06ld\n", gap.tv_sec, gap.tv_usec);
    }
}


int main(int argc, char *argv[]) {

    int len;
    if (argc == 2) {
        len = atoi(argv[1]);
        if (len > len){
            printf("행렬의 크기가 너무 커서 %d으로 설정합니다.\n", len);
            len = len;
        }
    } else {
        printf("Usage: %s <there's no matrix size>\n", argv[0]);
        exit(1);
    }

    // 행렬 동적 할당
    int (*matrix1)[len] = malloc(sizeof(int[len][len]));
    int (*matrix2)[len] = malloc(sizeof(int[len][len]));
    int (*sum)[len] = malloc(sizeof(int[len][len]));

    printf("행렬의 크기: %d x %d\n", len, len);
    // 랜덤한 값을 가진 len * len 행렬 생성
    generateRandomMatrix(len, matrix1);
    generateRandomMatrix(len, matrix2);

    matrixSum1(len, matrix1, matrix2, sum); // 행렬의 덧셈 행 우선 연산
    matrixSum2(len, matrix1, matrix2, sum); // 행렬의 덧셈 열 우선 연산
    matrixSum3(len, matrix1, matrix2, sum); // fork를 이용한 행렬의 덧셈 - 행 기준

    // 행렬 출력
    // printf("Sum of two %d x %d matrices:\n", len, len);
    // for (int i = 0; i < len; i++) {
    //     for (int j = 0; j < len; j++) {
    //         printf("%3d ", sum[i][j]);
    //     }
    //     printf("\n");
    // }
    return 0;
}
