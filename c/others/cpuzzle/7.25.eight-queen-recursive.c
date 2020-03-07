#include <stdio.h>
#define true 1
#define false 0
#define nmax 9
int num = 0;
int q[9];  // 记录8个皇后所占的列号
int C[9];  // 当前列是否安全的标志
int L[17]; // 当前(i-j)对角线是否安全的标志
int R[17]; // 当前(i+j)对角线是否安全的标志
void eightqueen(int);
int main() {
    int i = 0;
    for (i = 0; i < 9; i++) // 初始化为true
        C[i] = true;
    for (i = 0; i < 17; i++) {
        L[i] = true; // 初始化为false
        R[i] = true; // 初始化为false
    }
    eightqueen(1); // 调用求解八皇后问题
}
// eightqqueen( )函数
void eightqueen(int i) {
    int j, k, c = 0;
    for (j = 1; j <= 8; j++) {
        if ((C[j] == true && (L[i - j + nmax] == true) && (R[i + j]) == true)) {
            // 占用位置(i,j)，修改安全标志
            q[i] = j;
            C[j] = false;
            L[i - j + nmax] = false;
            R[i + j] = false;
            if (i < 8) {
                eightqueen(i + 1); // 没有放完则递归调用放下一个皇后
            } else                 // 放完进行输出处理
            {
                num++;
                printf("方案%2d：", num);
                for (k = 1; k <= 8; k++)
                    printf("%d", q[k]);
                printf("\n");
            }
            C[j] = true; // 修改安全标志，回溯
            L[i - j + nmax] = true;
            R[i + j] = true;
        }
    }
}
