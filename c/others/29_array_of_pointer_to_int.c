#include <stdio.h>
int main(){
    int *ap[3];
    int x=1, y=10, z=100;
    ap[0] = &x;
    ap[1] = &y;
    ap[2] = &z;
    printf("%d\n", *ap[0]);
    printf("%d\n", *ap[1]);
    printf("%d\n", *ap[2]);
    int ai[3] = {1, 2, 3}, *p;
    p = ai;
    printf("%d %d %d ", p[0], ai[0], *ai);
    printf("%d\n", *(p++));
    printf("%d %d %d ", (p--)[1], ai[1], *(ai+1));
    printf("%d\n", *(++p));
    printf("%d %d %d ", (p--)[1], ai[1], *(ai+1));
    printf("%d\n", *(p+1));
    printf("%d %d %d ", (--p)[2], ai[2], *(ai+2));
    printf("%d\n", *(p+2));
    return 0;
}
