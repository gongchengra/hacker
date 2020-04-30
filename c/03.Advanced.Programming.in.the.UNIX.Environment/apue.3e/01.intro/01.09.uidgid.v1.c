/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : 01.09.uidgid.v1.c
* Author : gongchengra@gmail.com
* Purpose :
* Creation Date : 2020-04-30
* Last Modified : 2020-04-30 16:02:03+0800
_._._._._._._._._._._._._._._._._._._._._.*/
#include <stdio.h>
#include <unistd.h>
int main(int argc, char **argv) {
    printf("uid = %d, gid = %d\n", getuid(), getgid());
    return 0;
}
