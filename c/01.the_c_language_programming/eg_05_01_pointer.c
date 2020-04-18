#include <stdio.h>
#include <stdlib.h>
int main(void) {
    int x = 1;
    int y;
    int values[] = {88, 56, 100, 2, 25};
    int *pv;
    pv = &x;
    /*    printf("%s",typeof(pv));*/
    printf("%ld\n%ld\n", (long)pv, sizeof(int));
    pv = values;
    for (y = 0; y <= 100; y++) {
        printf("%d\n", *(pv + y));
    }
    return 0;
}
