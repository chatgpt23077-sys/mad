#include <unistd.h>
#include <fcntl.h>
int main()
{
    int n, fd1;
    char buf[50];
    n = read(0, buf, 50);
    fd1 = open("target", O_WRONLY | O_APPEND);
    write(fd1, buf, n);
    return 0;
}
