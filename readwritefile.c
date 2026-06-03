#include <unistd.h>
#include <fcntl.h>
int main()
{
    int n, fd;
    char buf[30];
    fd = open("fork.c", O_RDONLY);
    n = read(fd, buf, 10);
    write(1, buf, 10);
    return 0;
}
