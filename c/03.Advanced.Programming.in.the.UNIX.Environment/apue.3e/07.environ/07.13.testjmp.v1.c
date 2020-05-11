/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : 07.13.testjmp.v1.c
* Author : gongchengra@gmail.com
* Purpose :
* Creation Date : 2020-05-11
* Last Modified : 2020-05-11 14:54:45+0800
_._._._._._._._._._._._._._._._._._._._._.*/
#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>
static int globval;
static jmp_buf jmpbuffer;
static void f2(void) { longjmp(jmpbuffer, 1); }
static void f1(int i, int j, int k, int l) {
    printf("in f1():\n");
    printf("globval = %d, autoval = %d, regival = %d,"
           " volaval = %d, statval = %d\n",
           globval, i, j, k, l);
    f2();
}
int main(void) {
    int autoval;
    register int regival;
    volatile int volaval;
    static int statval;
    globval = 1;
    autoval = 2;
    regival = 3;
    volaval = 4;
    statval = 5;
    if (setjmp(jmpbuffer) != 0) {
        printf("after longjmp:\n");
        printf("globval = %d, autoval = %d, regival = %d,"
               " volaval = %d, statval = %d\n",
               globval, autoval, regival, volaval, statval);
        exit(0);
    }
    /*
     * Change variables after setjmp, but before longjmp.
     */
    globval = 95;
    autoval = 96;
    regival = 97;
    volaval = 98;
    statval = 99;
    f1(autoval, regival, volaval, statval); /* never returns */
    exit(0);
}
