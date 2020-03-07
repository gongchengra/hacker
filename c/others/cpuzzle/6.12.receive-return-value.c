#include <stdio.h>
int max(int, int);
int main() {
    int a = 33, b = 55, c = 0, d = 100;
    max(a, b); // 6
    c = max(a, b);
    d = d + c; // 7
    printf("c=%d\n", d);
    return 0;
}
/*int max(int a, int b) {*/
/*    int x = 5, y = 8, c;*/
/*    if (a < b)*/
/*        c = b + x;*/
/*    else*/
/*        c = a + y;*/
/*    return c;*/
/*}*/
// or
int max(int a, int b) { return a < b ? (b + 5) : (a + 8); }
