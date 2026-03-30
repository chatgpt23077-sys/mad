#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main() {
    int pid;

    pid = fork();

    if(pid < 0) {
        perror("ERROR");
        exit(1);
    }
    else if(pid == 0) {
        sleep(2);
        printf("In child process\n");
        printf("pid = %d\n", getpid());
        printf("parent's pid = %d\n", getppid());
    }
    else {
        printf("In parent process\n");
        printf("pid = %d\n", getpid());
        printf("child's pid = %d\n", pid);
    }
}
