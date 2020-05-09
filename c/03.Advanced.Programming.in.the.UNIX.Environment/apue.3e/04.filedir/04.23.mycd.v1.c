/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : 04.23.mycd.v1.c
* Author : gongchengra@gmail.com
* Purpose :
* Creation Date : 2020-05-07
* Last Modified : 2020-05-07 15:13:00+0800
_._._._._._._._._._._._._._._._._._._._._.*/
#include <errno.h>  /* for definition of errno */
#include <stdarg.h> /* ISO C variable aruments */
#include <stdio.h>
#include <stdlib.h> //exit
#include <string.h>
#include <unistd.h>  //STDIN_FILENO
#define MAXLINE 4096 /* max line length */
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
    if (chdir("/tmp") < 0)
        err_sys("chdir failed");
    printf("chdir to /tmp succeeded\n");
    exit(0);
}
