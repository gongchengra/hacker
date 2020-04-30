/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : 01.06.hello.getpid.v1.c
* Author : gongchengra@gmail.com
* Purpose :
* Creation Date : 2020-04-30
* Last Modified : 2020-04-30 15:18:59+0800
_._._._._._._._._._._._._._._._._._._._._.*/
#include <stdio.h>
#include <unistd.h>
int main(int argc, char **argv){
	printf("hello world from process ID %ld\n", (long)getpid());
    return 0;
}

