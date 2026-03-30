#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

int main() {
    int pid, a[2], b[2];
    char str[30], buff1[30], buff2[30];

    pipe(a);
    pipe(b);

    pid = fork();

    if(pid == 0) {
        strcpy(str, "Welcome to OS lab");
        write(a[1], str, strlen(str)+1);

        sleep(2);

        read(b[0], buff1, sizeof(buff1));
        printf("Response from parent: %s\n", buff1);
    } else {
        read(a[0], buff2, sizeof(buff2));
        printf("Request from child: %s\n", buff2);

        strcpy(buff2, "Parent says hello");
        write(b[1], buff2, strlen(buff2)+1);
    }
}
