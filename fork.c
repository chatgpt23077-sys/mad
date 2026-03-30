#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main() {
    int pid;

    pid = fork();

    if(pid < 0) {
        perror("error occurred");
        exit(1);
    }
    else if(pid == 0) {
        printf("I'm a child\n");
        printf("my pid = %d\n", getpid());
        printf("my parent's pid = %d\n", getppid());
    }
    else {
        sleep(1);
        printf("I'm a parent\n");
        printf("my pid = %d\n", getpid());
        printf("my child pid = %d\n", pid);
        printf("my parent's pid = %d\n", getppid());
    }
}
