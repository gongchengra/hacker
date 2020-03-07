#include <stdio.h>
int main() {
    int a[3][3], i, j;
    // 分别给每行元素赋值
    for (i = 0, j = 0; j < 3; j++) // 访问a[0]所在行
        *(a[0] + j) = i + j;
    for (i = 1, j = 0; j < 3; j++) // 访问a[1]所在行
        *(a[1] + j) = i + j;
    for (i = 2, j = 0; j < 3; j++) // 访问a[2]所在行
        *(a[2] + j) = i + j;
    /*
        for (i=0;i<3;i++)
            for(j=0;j<3;j++)
                *(a[i]+j) = i+j; // a[i][j] = i+j;
    */
    // 1)标准输出方法
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
    // 2)以a[0]为基准分别输出每行元素
    for (j = 0; j < 3; j++) // 输出第1行
        printf("%d ", *(a[0] + j));
    printf("\n");
    for (j = 0; j < 3; j++)             // 输出第2行
        printf("%d ", *(a[0] + 3 + j)); // a[1]=a[0]+3
    printf("\n");
    for (j = 0; j < 3; j++)             // 输出第3行
        printf("%d ", *(a[0] + 6 + j)); // a[2]=a[0]+6
    printf("\n");
    // 3)使用计算公式表示地址的输出方法
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++)
            printf("%d ", *(a[0] + i * 3 + j));
        printf("\n");
    }
    // 4)分别输出每行的元素
    for (i = 0, j = 0; j < 3; j++) // 输出a[0]所在行
        printf("%d ", *(a[0] + j));
    printf("\n");
    for (i = 1, j = 0; j < 3; j++) // 输出a[1]所在行
        printf("%d ", *(a[1] + j));
    printf("\n");
    for (i = 2, j = 0; j < 3; j++) // 输出a[2]所在行
        printf("%d ", *(a[2] + j));
    printf("\n");
/*
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++)
            printf("%d ", *(a[i] + j));
        printf("\n");
    }
*/
}
