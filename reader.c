#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>

int main() {
    int fd;
    char str1[100], str2[100];

    while(1) {
        fd = open("fifo1", O_RDONLY);
        read(fd, str1, sizeof(str1));
        printf("User1: %s\n", str1);
        close(fd);

        fd = open("fifo1", O_WRONLY);
        fgets(str2, 100, stdin);
        write(fd, str2, strlen(str2)+1);
        close(fd);
    }
}
