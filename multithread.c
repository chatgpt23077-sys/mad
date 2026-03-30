#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

void *run1(void *arg);
void *run2(void *arg);
void *run3(void *arg);

int main() {
    pthread_t tid1, tid2, tid3;
    int i;

    printf("Thread demo\n");

    pthread_create(&tid1, NULL, run1, NULL);
    pthread_join(tid1, NULL);

    pthread_create(&tid2, NULL, run2, NULL);
    pthread_join(tid2, NULL);

    pthread_create(&tid3, NULL, run3, NULL);
    pthread_join(tid3, NULL);

    for(i = 0; i < 5; i++) {
        printf("Inside main\n");
        sleep(1);
    }
}

void *run1(void *arg) {
    int i;
    for(i = 0; i < 5; i++) {
        printf("Inside thread 1\n");
        sleep(1);
    }
    pthread_exit(0);
}

void *run2(void *arg) {
    int i;
    for(i = 0; i < 5; i++) {
        printf("Inside thread 2\n");
        sleep(1);
    }
    pthread_exit(0);
}

void *run3(void *arg) {
    int i;
    for(i = 0; i < 5; i++) {
        printf("Inside thread 3\n");
        sleep(1);
    }
    pthread_exit(0);
}
