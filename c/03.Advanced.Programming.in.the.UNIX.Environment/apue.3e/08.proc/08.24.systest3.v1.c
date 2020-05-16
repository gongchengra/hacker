/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : 08.24.systest3.v1.c
* Author : gongchengra@gmail.com
* Purpose : gcc -c system.c && gcc system.o 08.24.systest3.v1.c -o tsys
* Creation Date : 2020-05-15
* Last Modified : 2020-05-15 23:26:46+0800
_._._._._._._._._._._._._._._._._._._._._.*/
#include <stdio.h>
#include <stdlib.h>
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
int main(int argc, char **argv) {
    int status;
    if (argc < 2)
        printf("command-line argument required.\n");
    if ((status = system(argv[1])) < 0)
        printf("system() error\n");
    pr_exit(status);
    exit(0);
}
