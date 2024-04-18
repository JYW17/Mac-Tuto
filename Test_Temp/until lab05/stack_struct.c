#include <stdio.h>
#include <stdlib.h>

int glob1, glob2;

int func2(int x ,int y){
    int f2_local1 = 21, f2_local2 = 22;

    int *ptr;

    ptr = &f2_local2;


    printf("func2 local: \n\t%p \n\t%p\n", &f2_local1, &f2_local2);

    printf("*ptr: %d\n", *ptr);
    printf("*ptr+1: %d\n", *(ptr+1));
    printf("*ptr+2: %d\n", *(ptr+2));
    printf("*ptr+3: %d\n", *(ptr+3));
    printf("*ptr+4: %d\n", *(ptr+4));

    printf("*ptr-1: %d\n", *(ptr-1));
    printf("*ptr-2: %d\n", *(ptr-2));
    printf("*ptr-3: %d\n", *(ptr-3));
    printf("*ptr-4: %d\n", *(ptr-4));
    
    printf("f2_local1: %d\n", f2_local1);
    printf("f2_local2: %d\n", f2_local2);

    // *(ptr+4) = 0x16bbef210;

    return 1000;
}

int func1(void){
    int rev, f1_local1, f1_local2;
    printf("func1 local: \n\t%p \n\t%p\n", &f1_local1, &f1_local2);
    rev = func2(111, 112);

    printf("rev: %d\n", rev);

    return 0;
}

int main(void)
{
    int m_local1, m_local2;
    int *dynamic_addr = malloc(sizeof(int) * 4);

    printf("main local: \n\t%p \n\t%p\n", &m_local1, &m_local2);
    func1();

    // printf("dynamic_addr: \n\t%p\n", dynamic_addr);
    // printf("global: \n\t%p \n\t%p\n", &glob1, &glob2);
    // printf("functions: \n\t%p \n\t%p\n", &func1, &func2);
    return 0;
}
