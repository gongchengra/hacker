/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : seek.v1.c
* Author : gongchengra@gmail.com
* Purpose :
* Creation Date : 2020-05-01
* Last Modified : 2020-05-01 15:46:44+0800
_._._._._._._._._._._._._._._._._._._._._.*/
#include <stdio.h>
#include <unistd.h>
int main(int argc, char **argv) {
    if (lseek(STDIN_FILENO, 0, SEEK_CUR) == -1)
        printf("cannot seek\n");
    else
        printf("seek OK\n");
    return 0;
}
