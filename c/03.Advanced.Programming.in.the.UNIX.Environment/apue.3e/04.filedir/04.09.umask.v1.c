/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : 04.09.umask.v1.c
* Author : gongchengra@gmail.com
* Purpose :
* Creation Date : 2020-05-06
* Last Modified : 2020-05-06 00:21:16+0800
_._._._._._._._._._._._._._._._._._._._._.*/
#include <errno.h>  /* for definition of errno */
#include <fcntl.h>  //access
#include <stdarg.h> /* ISO C variable aruments */
#include <stdio.h>
#include <stdlib.h> //exit
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>  //STDIN_FILENO
#define MAXLINE 4096 /* max line length */
#define RWRWRW (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)
static void err_doit(int errnoflag, int error, const char *fmt, va_list ap) {
    char buf[MAXLINE];
    vsnprintf(buf, MAXLINE - 1, fmt, ap);
    if (errnoflag)
        snprintf(buf + strlen(buf), MAXLINE - strlen(buf) - 1, ": %s",
                 strerror(error));
    strcat(buf, "\n");
    fflush(stdout); /* in case stdout and stderr are the same */
    fputs(buf, stderr);
    fflush(NULL); /* flushes all stdio output streams */
}
void err_sys(const char *fmt, ...) {
    va_list ap;

    va_start(ap, fmt);
    err_doit(1, errno, fmt, ap);
    va_end(ap);
    exit(1);
}
int main(int argc, char **argv) {
    umask(0);
    if (creat("foo.o", RWRWRW) < 0)
        err_sys("creat error for foo");
    umask(S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
    if (creat("bar.o", RWRWRW) < 0)
        err_sys("creat error for bar");
    printf("foo.o and bar.o created.\n");
    exit(0);
}
