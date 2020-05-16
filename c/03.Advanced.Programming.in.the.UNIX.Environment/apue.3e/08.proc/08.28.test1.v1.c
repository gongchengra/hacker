/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : 08.28.test1.v1.c
* Author : gongchengra@gmail.com
* Purpose :
* Creation Date : 2020-05-16
* Last Modified : 2020-05-16 09:23:28+0800
_._._._._._._._._._._._._._._._._._._._._.*/
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
void err_sys(const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    char *s = va_arg(ap, char *);
    printf("%s\n", s);
    va_end(ap);
    exit(1);
}
int main(int argc, char **argv) {
    pid_t pid;
    if ((pid = fork()) < 0)
        err_sys("fork error");
    else if (pid != 0) { /* parent */
        sleep(2);
        exit(2); /* terminate with exit status 2 */
    }
    if ((pid = fork()) < 0)
        err_sys("fork error");
    else if (pid != 0) { /* first child */
        sleep(4);
        abort(); /* terminate with core dump */
    }
    if ((pid = fork()) < 0)
        err_sys("fork error");
    else if (pid != 0) { /* second child */
        execl("/bin/dd", "dd", "if=/etc/passwd", "of=/dev/null", NULL);
        exit(7); /* shouldn't get here */
    }
    if ((pid = fork()) < 0)
        err_sys("fork error");
    else if (pid != 0) { /* third child */
        sleep(8);
        exit(0); /* normal exit */
    }
    sleep(6);                /* fourth child */
    kill(getpid(), SIGKILL); /* terminate w/signal, no core dump */
    exit(6);                 /* shouldn't get here */
}
