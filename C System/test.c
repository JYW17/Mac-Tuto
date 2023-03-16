#include <stdio.h>
#include <time.h>

long fibo(long n){
    if(n<2){
        return n;
    }
    return fibo(n-2) + fibo(n-1);
}





int main(void){
    // int count1, count2, count3, rst1, rst2;
    // rst1 = 0;
    // rst2 = 0;
    // count1 = count2 = count3 = 5;
    // printf("%d %d %d\n", count1, count2, count3);
    
    // count1++;
    // rst1 = -++count2;
    // rst2 = -count3++;
    // // rst = (-count3)++;

    // printf("%d %d %d %d %d\n", count1, count2, count3, rst1, rst2);
    
    // for (int i = 0; i < 10; ++i){
    //     printf("%d\n", i);
    // }

    clock_t start = clock();
    printf("%ld", fibo(50));
    clock_t end = clock();
    
    printf("소요 시간: %lf\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}