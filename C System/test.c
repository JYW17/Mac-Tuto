#include <stdio.h>

int main(void){
    printf("Hello World!");

    int a,b;
    char str[100];
    scanf("%d %d", &a, &b);
    scanf("%s", str);
    printf("%s", str);
    printf("%d %d!", a,b);
    
    return 0;
}