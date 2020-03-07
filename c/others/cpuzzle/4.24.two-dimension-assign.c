#include <stdio.h>
int main() {
    int a[3][3], i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            a[i][j] = 1 + i + j;
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}
