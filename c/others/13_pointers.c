/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : 13_points.c
* Author : gongchengra@gmail.com
* Purpose :http://codinghighway.com/?p=724
* Creation Date : 2014-11-11
* Last Modified :
_._._._._._._._._._._._._._._._._._._._._.*/
#include <stdio.h>
int main(void) {
    int a[] = {1, 2, 3};
    int *p = a;
    int x = a[2];
    int y = 1 [a];
    printf("%d\n", x);
    printf("%d\n", y);
    printf("%d\n", *p);
    printf("%ld %p\n", (long)p, p);
}
