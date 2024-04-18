#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void sub(int p){
    int i;
    static int s = 100;
    register int r = 200;


    printf("%d, %d\n", s, i); 
    printf("register: %d\n", r);
    r++;
    printf("register: %d\n", r);

    s++;
    i++;
}

int main(void){
    
    int i;
    sub(100);
    sub(10);


}
