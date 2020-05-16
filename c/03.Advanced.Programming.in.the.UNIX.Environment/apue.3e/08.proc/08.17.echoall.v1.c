/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : 08.17.echoall.v1.c
* Author : gongchengra@gmail.com
* Purpose :
* Creation Date : 2020-05-15
* Last Modified : 2020-05-15 16:05:57+0800
_._._._._._._._._._._._._._._._._._._._._.*/
#include <stdio.h>
int main(int argc, char *argv[]) {
    int i;
    char **ptr;
    extern char **environ;
    for (i = 0; i < argc; i++) /* echo all command-line args */
        printf("argv[%d]: %s\n", i, argv[i]);
    for (ptr = environ; *ptr != 0; ptr++) /* and all env strings */
        printf("%s\n", *ptr);
    exit(0);
}
