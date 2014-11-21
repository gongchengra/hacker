/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : eg_06_01_struct.c

* Author : gongchengra@gmail.com

* Purpose :

* Creation Date : 2014-11-18

* Last Modified :

_._._._._._._._._._._._._._._._._._._._._.*/

#include <stdio.h>
#include <math.h>
int main(void)
{
    struct point {
        int x;
        int y;
    } pt;
    struct rect {
        struct point pt1;
        struct point pt2;
    } screen;
    double dist;
    pt.x = 320;
    pt.y = 300;
    printf("%d, %d\n", pt.x, pt.y);
    dist = sqrt((double)pt.x * pt.x + (double)pt.y * pt.y);
    printf("%f\n", dist);
    return 0;
}
