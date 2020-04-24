/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : eg_06_01_struct.c
* Author : gongchengra@gmail.com
* Purpose :
* Creation Date : 2014-11-18
* Last Modified :
_._._._._._._._._._._._._._._._._._._._._.*/
#include <math.h>
#include <stdio.h>
int main(void) {
    struct point {
        int x;
        int y;
    } pt;
    double dist;
    pt.x = 300;
    pt.y = 400;
    printf("%d, %d\n", pt.x, pt.y);
    dist = sqrt((double)pt.x * pt.x + (double)pt.y * pt.y);
    printf("%.2f\n", dist);
    struct point *pp;
    pp = &pt;
    printf("%d, %d\n", (*pp).x, (*pp).y);
    printf("%d, %d\n", pp->x, pp->y);
    struct rect {
        struct point pt1;
        struct point pt2;
    } r;
    struct point p1, p2;
    p1.x = 500;
    p1.y = 600;
    r.pt1 = p1;
    p2.x = 700;
    p2.y = 800;
    r.pt2 = p2;
    struct rect *rp = &r;
    printf("%d\n", r.pt1.x);
    printf("%d\n", rp->pt1.y);
    printf("%d\n", (r.pt2).x);
    printf("%d\n", (rp->pt2).y);
    return 0;
}
