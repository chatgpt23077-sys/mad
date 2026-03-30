#include<stdio.h>
#include<string.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#include<unistd.h>

struct msgbuf {
    long mtype;
    char mtext[100];
};

int main() {
    int pid, msqid;
    struct msgbuf msg;

    msqid = msgget((key_t)151, IPC_CREAT | 0666);
    pid = fork();

    if(pid == 0) {
        msg.mtype = 1;
        strcpy(msg.mtext, "Hello from child");
        msgsnd(msqid, &msg, sizeof(msg.mtext), 0);

        msgrcv(msqid, &msg, sizeof(msg.mtext), 2, 0);
        printf("Child received: %s\n", msg.mtext);
    } else {
        msgrcv(msqid, &msg, sizeof(msg.mtext), 1, 0);
        printf("Parent received: %s\n", msg.mtext);

        msg.mtype = 2;
        strcat(msg.mtext, " - reply from parent");
        msgsnd(msqid, &msg, sizeof(msg.mtext), 0);
    }
}
