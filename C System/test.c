#include <stdio.h>

int main(void){
    int count1, count2, count3, rst1, rst2;
    rst1 = 0;
    rst2 = 0;
    count1 = count2 = count3 = 5;
    printf("%d %d %d\n", count1, count2, count3);
    
    count1++;
    rst1 = -++count2;
    rst2 = -count3++;
    // rst = (-count3)++;

    printf("%d %d %d %d %d\n", count1, count2, count3, rst1, rst2);
    
    for (int i = 0; i < 10; ++i){
        printf("%d\n", i);
    }



    return 0;
}