/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : eg_06_01_struct.c

* Author : gongchengra@gmail.com

* Purpose :

* Creation Date : 2014-11-18

* Last Modified :

_._._._._._._._._._._._._._._._._._._._._.*/

#include <stdio.h>
#include <math.h>
#define XMAX 1920
#define YMAX 1080

/* makepoint:  make a point from x and y components */
struct point makepoint(int x, int y)
{
    struct point temp;
    temp.x = x;
    temp.y = y;
    return temp;
}

/* addpoints: add two points */
struct point addpoint(struct point p1, struct point p2)
{
    p1.x += p2.x;
    p1.y += p2.y;
    return p1;
}

/* ptinrect: return 1 if p in r, 0 if not */
int ptinrect(struct point p, struct rect r)
{
    return p.x >= r.pt1.x && p.x < r.pt2.x
        && p.y >= r.pt1.y && p.y < r.pt2.y;
}

int main(void)
{
    struct point {
        int x;
        int y;
    };

    struct rect {
        struct point pt1;
        struct point pt2;
    };

    double dist, sqrt(double);
    point pt;
    point middle;
    point makepoint(int,int);
    rect screen;

    pt.x = 320;
    pt.y = 300;
    printf("%d, %d\n", pt.x, pt.y);
    dist = sqrt((double)pt.x * pt.x + (double)pt.y * pt.y);
    printf("%f\n", dist);

    /*    screen.pt1.x = 0;*/
    /*    screen.pt1.y = 0;*/
    /*    screen.pt2.x = 1920;*/
    /*    screen.pt2.y = 1080;*/
    screen.pt1 = makepoint(0, 0);
    screen.pt2 = makepoint(XMAX, YMAX);
    middle = makepoint((screen.pt1.x + screen.pt2.x)/2,
            (screen.pt1.y + screen.pt2.y)/2);
    return 0;
}
