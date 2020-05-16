/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : 08.23.systest1.v1.c
* Author : gongchengra@gmail.com
* Purpose : gcc -c system.c && gcc system.o 08.23.systest1.v1.c -o date.exe
* Creation Date : 2020-05-15
* Last Modified : 2020-05-15 23:09:01+0800
_._._._._._._._._._._._._._._._._._._._._.*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
void pr_exit(int status) {
    if (WIFEXITED(status))
        printf("normal termination, exit status = %d\n", WEXITSTATUS(status));
    else if (WIFSIGNALED(status))
        printf("abnormal termination, signal number = %d%s\n", WTERMSIG(status),
#ifdef WCOREDUMP
               WCOREDUMP(status) ? " (core file generated)" : "");
#else
               "");
#endif
    else if (WIFSTOPPED(status))
        printf("child stopped, signal number = %d\n", WSTOPSIG(status));
}
int main(void) {
    int status;
    if ((status = system("date")) < 0)
        printf("system() error");
    pr_exit(status);
    if ((status = system("nosuchcommand")) < 0)
        printf("system() error");
    pr_exit(status);
    if ((status = system("who; exit 44")) < 0)
        printf("system() error");
    pr_exit(status);
    exit(0);
}
