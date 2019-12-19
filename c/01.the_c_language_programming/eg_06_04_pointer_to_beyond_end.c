#include <stdio.h>
#include <stdlib.h>
#define LEN 10
int main() {
    int a[LEN], *pstart, *pend;
    for (int i = 0; i < LEN; i++) {
        a[i] = i;
        printf("%d ", i);
    }
    pstart = &a[0];
    // pointer arithmetic that involves the first element beyond
    // the end of an array (that is, &a[LEN]) will work correctly.
    pend = &a[LEN];
    printf("\n%d", *(pstart + (pend - pstart) / 2));
}
