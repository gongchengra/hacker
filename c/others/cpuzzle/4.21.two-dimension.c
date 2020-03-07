#include <stdio.h>
int main() {
    int a[3][3], i, j, k = 0;
    a[0][0] = 212;
    a[0][1] = 175;
    a[0][2] = 65;
    a[1][0] = -99;
    a[1][1] = -55;
    a[1][2] = -31;
    for (i = 0; i < 2; i++)
        for (j = 0; j < 3; j++)
            if (a[i][j] < 0) {
                printf("a[%d][%d]=%d\n", i, j, a[i][j]);
                ++k;
            }
    if (k > 0) {
        printf("There are %d times.\n", k);
    }
    printf("no found.\n ");
    return 0;
}
