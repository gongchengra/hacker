#include <stdio.h>
#define true 1
#define false 0
void print(int[]); // 函数声明
void movequeen(int, int, int[], int[], int[]);
void eightqueen();
int main() {
    eightqueen(); // 调用求解八皇后问题
}
/******************************/
/* 打印输出一个解的函数 */
/******************************/
void print(int s[]) {
    int k;
    printf("\n行号： 1 2 3 4 5 6 7 8\n");
    printf("列号：");
    for (k = 1; k <= 8; k++)
        printf("%2d", s[k]);
    printf("\n");
}
/******************************/
/* 移去位置(i,j)上的皇后函数 */
/******************************/
void movequeen(int i, int j, int a[], int b[], int c[]) {
    a[j] = true;
    b[i + j] = true;
    c[i - j + 9] = true;
}
// 在此位置插入eightqqueen( )函数
void eightqueen() {
    int i, j;
    int s[9];
    int a[9], b[17], c[17];
    for (i = 2; i <= 16; i++) {
        if (i >= 2 && i <= 9)
            a[i - 1] = true;
        b[i] = true;
        c[i] = true;
    }
    i = 1;
    j = 1;
    while (i >= 1) {     // 当i=0时终止循环
        while (j <= 8) { // 在当前行i上寻找安全位置；
            if (a[j] && b[i + j] && c[i - j + 9])
                break;
            j++;
        }
        if (j <= 8) { // 找到安全位置(i,j)
            a[j] = false;
            b[i + j] = false;
            c[i - j + 9] = false;
            s[i] = j;                     // 皇后位置j入栈
            if (i == 8) {                 // 找到一个解,输出解
                print(s);                 // 打印输出一个解
                movequeen(i, j, a, b, c); // 移去位置(i,j)上的皇后
                i--;
                j = s[i];                 // 退栈，回溯到上一个皇后
                movequeen(i, j, a, b, c); // 移去位置(i,j)上的皇后
                j++;                      // 修改栈顶皇后的位置
            } else {
                i++;
                j = 1; // 准备放置下一个皇后
            }
        } else {
            i--;          // 退栈
            if (i >= 1) { // 栈不空,移去皇后
                j = s[i];
                movequeen(i, j, a, b, c); // 移去皇后
                j++;
            }
        }
    }
}
