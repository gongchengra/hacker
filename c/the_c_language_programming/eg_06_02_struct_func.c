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
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

struct point {
    int x;
    int y;
};

struct rect {
    struct point pt1;
    struct point pt2;
};

/* makepoint:  make a point from x and y components */
struct point makepoint(int x, int y)
{
    struct point temp;
    temp.x = x;
    temp.y = y;
    return temp;
}

/* makerect: make a rec from two points */
struct rect makerect(struct point x, struct point y)
{
    struct rect temp;
    temp.pt1 = x;
    temp.pt2 = y;
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

/* canonrect: canonicalize coordinates of rectangle */
struct rect canonrect(struct rect r)
{
    struct rect temp;
    temp.pt1.x = min(r.pt1.x, r.pt2.x);
    temp.pt1.y = min(r.pt1.y, r.pt2.y);
    temp.pt2.x = min(r.pt1.x, r.pt2.x);
    return temp;
}

int main(void)
{
    double dist, sqrt(double);
    struct point *pp, pt, middle, ptmp;
    struct rect screen;

    pt = makepoint(320,240);
    ptmp = makepoint(640,480);
    printf("%d, %d\n", pt.x, pt.y);
    printf("%d, %d\n", ptmp.x, ptmp.y);
    ptmp = addpoint(pt, ptmp);
    pp = &ptmp;
    printf("%d, %d\n", (*pp).x, (*pp).y);
    printf("%d, %d\n", pp->x, pp->y);
    dist = sqrt((double)pt.x * pt.x + (double)pt.y * pt.y);
    printf("%f\n", dist);

    screen = makerect(makepoint(0,0), makepoint(XMAX, YMAX));
    middle = makepoint((screen.pt1.x + screen.pt2.x)/2,
            (screen.pt1.y + screen.pt2.y)/2);
    printf("%d, %d\n", middle.x, middle.y);
    pt = makepoint(2000,2000);
    printf(ptinrect(pt, screen) == 1 ? "point is in rec.\n ":"point is out rect.\n");
    return 0;
}
