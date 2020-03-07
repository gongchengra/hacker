#include <stdio.h>
int main() {
    int a[3][3], i, j, *p;
    p = a[0];
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            *(p + i * 3 + j) = i * 3 + j + 1; // 等效于p[i*3+j]=i*3+j+1;
            // equals a[i][j] = i*3+j+1;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++)
            printf("%d ", p[i * 3 + j]); // 等效于printf( "%d ",*(p+i*3+j));
        printf("\n");
    }
    p = &a[2][2];
    printf("%d\n", *p);
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++)
            printf("%d ", p[-i * 3 - j]); // 等效于printf( "%d ",*(p-i*3-j));
        printf("\n");
    }
}
