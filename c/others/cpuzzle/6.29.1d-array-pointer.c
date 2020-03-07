#include <stdio.h>
void display(int (*a)[3]);
void disp(int (*a)[3]);
int main() {
    int a[][3] = {{15, 38, -52}, {-97, -85, 88}, {331, 457, -56}};
    display(a); // 按列输出
    printf("\n");
    disp(a); // 先按列输出再按行输出
    return 0;
}
void disp(int (*a)[3]) {
    int i, j;
    for (j = 0; j < 3; j++) // 按列输出
    {
        for (i = 0; i < 3; i++)
            printf("%5d", *(a[i] + j));
        printf("\n");
    }
    printf("\n");
    for (i = 0; i < 3; i++) // 按行输出
    {
        for (j = 0; j < 3; j++)
            printf("%5d", *(a[i] + j));
        printf("\n");
    }
    printf("\n");
    for (i = 0; i < 3; i++) // 按行输出
        printf("%5d%5d%5d\n", *a[i], *(a[i] + 1), *(a[i] + 2));
}
void display(int (*a)[3]) {
    int i;
    for (i = 0; i < 3; i++)
        printf("%5d", *a[i]); // 第0列
    printf("\n");
    for (i = 0; i < 3; i++)
        printf("%5d", *(a[i] + 1)); // 第1列
    printf("\n");
    for (i = 0; i < 3; i++)
        printf("%5d", *(a[i] + 2)); // 第2列
    printf("\n");
}
