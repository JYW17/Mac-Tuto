#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_BUF 64

char fname[] = "newfile_lseek.txt";
char dummy_date[] = "abcdefg\n";

int main(void){
    int fd, write_size, read_size, new_offset;
    char buf[MAX_BUF];

    fd = open(fname, O_RDWR | O_CREAT | O_TRUNC/*| O_EXCL*/, 0644);
    write_size = write(fd, dummy_date, sizeof(dummy_date));
    printf("write_size: %d\n", write_size);
    close(fd);

    fd = open(fname, O_RDWR);
    new_offset = lseek(fd, 3, SEEK_SET);
    read_size = read(fd, buf, MAX_BUF);
    printf("read_size: %d\n", read_size);
    write_size = write(STDOUT_FILENO, buf, read_size);
    printf("write_size2: %d\n", write_size);
    close(fd);
    
}