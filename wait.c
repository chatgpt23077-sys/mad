#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
    pid_t ret_value;
    printf("\nThe process id is %d\n", getpid());
    ret_value = fork();
    if (ret_value < 0)
    {
        printf("\nFork Failure\n");
    }
    else if (ret_value == 0)
    {
        sleep(20);
        printf("\nchild process\n");
        printf("\nThe process id is %d\n", getpid());
    }
    else
    {
        wait(NULL);
        printf("parent process\n");
        printf("\nThe process id is %d\n", getpid());
    }
    return 0;
}
