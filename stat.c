#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>
#include<time.h>

int main(int argc, char *argv[]) {
    struct stat buf;

    if(stat(argv[1], &buf) < 0) {
        perror("error in opening file");
        exit(1);
    }

    printf("user id = %d\n", buf.st_uid);
    printf("group id = %d\n", buf.st_gid);
    printf("number of links = %d\n", buf.st_nlink);
    printf("File size = %ld\n", buf.st_size);
    printf("permission = %o\n", buf.st_mode);
    printf("inode number = %ld\n", buf.st_ino);

    printf("Time of last change = %s", ctime(&buf.st_ctime));
    printf("Time of last access = %s", ctime(&buf.st_atime));
    printf("Time of last modification = %s", ctime(&buf.st_mtime));
}
