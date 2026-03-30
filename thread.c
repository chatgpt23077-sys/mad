#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

void *run(void *arg);

int main() {
    pthread_t tid;
    int i;

    printf("Demo of thread\n");

    pthread_create(&tid, NULL, run, NULL);
    pthread_join(tid, NULL);

    for(i = 0; i <= 4; i++) {
        printf("Inside main\n");
        sleep(1);
    }
}

void *run(void *arg) {
    int i;
    for(i = 0; i <= 4; i++) {
        printf("Inside thread\n");
        sleep(1);
    }
    pthread_exit(0);
}
