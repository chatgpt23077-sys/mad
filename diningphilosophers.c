#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

pthread_mutex_t chopstick[5];
pthread_t philosopher[5];

void* runner(void* arg) {
    int i = *(int*)arg;

    printf("Philosopher %d is thinking\n", i);
    sleep(2);

    pthread_mutex_lock(&chopstick[i]);
    pthread_mutex_lock(&chopstick[(i+1)%5]);

    printf("Philosopher %d is eating\n", i);
    sleep(3);

    pthread_mutex_unlock(&chopstick[i]);
    pthread_mutex_unlock(&chopstick[(i+1)%5]);

    printf("Philosopher %d finished eating\n", i);
    return NULL;
}

int main() {
    int i, a[5];

    for(i = 0; i < 5; i++) {
        pthread_mutex_init(&chopstick[i], NULL);
        a[i] = i;
        pthread_create(&philosopher[i], NULL, runner, &a[i]);
    }

    for(i = 0; i < 5; i++) {
        pthread_join(philosopher[i], NULL);
    }
}
