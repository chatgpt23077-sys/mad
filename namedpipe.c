#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>

int main() {
    int fd;
    char str1[100], str2[100];

    mkfifo("fifo1", 0644);
    printf("Named pipe created\n");

    while(1) {
        fd = open("fifo1", O_WRONLY);
        fgets(str1, 100, stdin);
        write(fd, str1, strlen(str1)+1);
        close(fd);

        fd = open("fifo1", O_RDONLY);
        read(fd, str2, sizeof(str2));
        printf("User2: %s\n", str2);
        close(fd);
    }
}
