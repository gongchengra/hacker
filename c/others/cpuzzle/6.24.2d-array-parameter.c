#include <stdio.h>
#define SIZE 5
void mult(int[][SIZE], int n);
void disp(int[][SIZE]);
int main() {
    static int x[][SIZE] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}};
    printf("Original matrix : \n");
    disp(x);
    mult(x, 3);
    printf("Multiplied by 3: \n");
    disp(x);
}
// function mult：乘法
void mult(int a[][SIZE], int n) {
    int i, j;
    for (i = 0; i < 2; ++i)
        for (j = 0; j < SIZE; ++j)
            a[i][j] *= n;
}
// function disp：输出二维数组
void disp(int b[][SIZE]) {
    int i, j;
    for (i = 0; i < 2; ++i) {
        for (j = 0; j < SIZE; ++j)
            printf("%5d", b[i][j]);
        printf("\n");
    }
}
