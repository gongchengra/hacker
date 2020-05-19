/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : 09.11.orphan3.v1.c
* Author : gongchengra@gmail.com
* Purpose :
* Creation Date : 2020-05-19
* Last Modified : 2020-05-19 14:28:46+0800
_._._._._._._._._._._._._._._._._._._._._.*/
#include <errno.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#define MAXLINE 4096
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
static void sig_hup(int signo) {
    printf("SIGHUP received, pid = %ld\n", (long)getpid());
}
static void pr_ids(char *name) {
    printf("%s: pid = %ld, ppid = %ld, pgrp = %ld, tpgrp = %ld\n", name,
           (long)getpid(), (long)getppid(), (long)getpgrp(),
           (long)tcgetpgrp(STDIN_FILENO));
    fflush(stdout);
}
int main(void) {
    char c;
    pid_t pid;
    pr_ids("parent");
    if ((pid = fork()) < 0) {
        err_sys("fork error");
    } else if (pid > 0) { /* parent */
        sleep(5);         /* sleep to let child stop itself */
    } else {              /* child */
        pr_ids("child");
        signal(SIGHUP, sig_hup); /* establish signal handler */
        kill(getpid(), SIGTSTP); /* stop ourself */
        pr_ids("child");         /* prints only if we're continued */
        if (read(STDIN_FILENO, &c, 1) != 1)
            printf("read error %d on controlling TTY\n", errno);
    }
    exit(0);
}
