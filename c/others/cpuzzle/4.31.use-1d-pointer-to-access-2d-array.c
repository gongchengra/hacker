#include <stdio.h>
int main() {
    int i, j, a[3][3], (*p)[3];
    p = a;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            *(*(p + i) + j) = i * 3 + j + 1;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++) {
            if (i != 0 && j % 3 == 0)
                printf("\n");
            printf("%d ", *(*(p + i) + j));
        }
    printf("\n");
    printf("%d,%d,%d\n", *p[0], *(p[0] + 1), *(p[0] + 2)); // 输出第1行
    printf("%d,%d,%d\n", *p[0], *p[1], *p[2]);             // 输出第1列
    printf("%d,%d,%d\n", **p, *(*p + 1), *(*p + 2));       // 输出第1行
    printf("%d,%d,%d\n", **p, **(p + 1), **(p + 2));       // 输出第1列
    printf("%d,%d,%d\n", *(*(p + 1)), *(*(p + 1) + 1),
           *(*(p + 1) + 2)); // 输出第2行
    printf("%d,%d,%d\n", *(*p + 1), *(*(p + 1) + 1),
           *(*(p + 2) + 1)); // 输出第2列
    return 0;
}
