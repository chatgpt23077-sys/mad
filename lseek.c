#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

int main() {
    int fd;
    char buf[50];

    fd = open("seek.txt", O_RDWR);

    if(fd < 0) {
        perror("ERROR with file");
        exit(1);
    }

    read(fd, buf, 10);
    write(1, buf, 10);
    printf("\n");

    lseek(fd, 5, SEEK_CUR);
    read(fd, buf, 10);
    write(1, buf, 10);
    printf("\n");

    lseek(fd, 5, SEEK_SET);
    read(fd, buf, 10);
    write(1, buf, 10);
    printf("\n");

    lseek(fd, -11, SEEK_END);
    read(fd, buf, 10);
    write(1, buf, 10);
    printf("\n");
}
