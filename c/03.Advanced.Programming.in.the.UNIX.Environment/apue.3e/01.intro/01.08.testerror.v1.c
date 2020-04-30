/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : 01.08.testerror.v1.c
* Author : gongchengra@gmail.com
* Purpose :
* Creation Date : 2020-04-30
* Last Modified : 2020-04-30 15:49:30+0800
_._._._._._._._._._._._._._._._._._._._._.*/
#include <stdio.h>
#include <string.h>
#include <errno.h> // /usr/include/sys/errno.h
int main(int argc, char **argv){
	fprintf(stderr, "EACCES: %s\n", strerror(EACCES));
	errno = ENOENT;
	perror(argv[0]);
    return 0;
}

