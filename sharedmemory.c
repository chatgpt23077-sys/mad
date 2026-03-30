#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<string.h>
#include<sys/shm.h>

int main() {
    int pid, shmid;
    char *p;

    shmid = shmget((key_t)224, 1024, IPC_CREAT | 0666);
    p = (char*)shmat(shmid, NULL, 0);

    pid = fork();

    if(pid == 0) {
        strcpy(p, "Data in shared memory");
    } else {
        sleep(1);
        printf("%s\n", p);
    }
}
