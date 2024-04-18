#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

char fname[] = "newfile1.txt";
char dummy_data[] = "opqrstuvwxyz";

int main(void){
    int fd, w_size, r_size;
    char buf[6];

    fd = open(fname, O_RDWR | O_CREAT | O_TRUNC, 0644);
    w_size = write(fd, dummy_data, sizeof(dummy_data));
        
    lseek(fd, SEEK_SET, 6);
    r_size = read(fd, buf, 6);
    write(STDOUT_FILENO, buf, sizeof(buf));
    printf("w_size: %d\n", w_size);
    

}