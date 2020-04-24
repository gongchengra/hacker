/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : 83_system_calls.c
* Author : gongchengra@gmail.com
* Purpose :
https://www.geeksforgeeks.org/input-output-system-calls-c-create-open-close-read-write/
* Creation Date : 2020-04-21
* Last Modified : 2020-04-21 18:48:47+0800
_._._._._._._._._._._._._._._._._._._._._.*/
#include <errno.h>
#include <fcntl.h> //for open
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h> //for close
extern int errno;
void openClose() {
    int fd = open("foo.txt", O_RDONLY | O_CREAT);
    printf("fd = %d/n", fd);
    if (fd == -1) {
        // print which type of error have in a code
        printf("Error Number % d\n", errno);
        // print program detail "Success or failure"
        perror("Program");
    }
    if (close(fd) < 0) {
        perror("c1");
        exit(1);
    }
    printf("\nclosed the fd.\n");
}
void readWrite() {
    int fd, sz;
    char *c = (char *)calloc(100, sizeof(char));
    fd = open("foo.txt", O_RDONLY);
    if (fd < 0) {
        perror("r1");
        exit(1);
    }
    sz = read(fd, c, 10);
    printf("called read(%d, c, 10).  returned that %d bytes  were read.\n", fd,
           sz);
    c[sz] = '\0';
    printf("Those bytes are as follows: %s\n", c);
    fd = open("foo.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        perror("r1");
        exit(1);
    }
    sz = write(fd, "hello geeks\n", strlen("hello geeks\n"));
    printf("called write(% d, \"hello geeks\\n\", %d)."
           " It returned %d\n",
           fd, (int)strlen("hello geeks\n"), sz);
    close(fd);
}
void helloWorld() {
    int fd[2];
    char buf[12] = "hello world";

    // assume foobar.txt is already created
    fd[0] = open("foobar.txt", O_RDWR);
    fd[1] = open("foobar.txt", O_RDWR);

    write(fd[0], buf, strlen(buf));
    /*    write(STDIN_FILENO, buf, read(fd[0], buf, 12));*/
    write(STDIN_FILENO, buf, strlen(buf));
    close(fd[0]);
    close(fd[1]);
}
void inOut() {
    char message[20];
    read(STDOUT_FILENO, message, 20);
    write(STDIN_FILENO, message, 20);
}
int main(int argc, char **argv) {
    openClose();
    readWrite();
    helloWorld();
    inOut();
}
