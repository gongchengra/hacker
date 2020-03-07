#include <stdio.h>
int main() {
    int n, fibonacci[20] = {0, 1};                  // 初始化
    printf("%-5d%-5d", fibonacci[0], fibonacci[1]); // 左端对齐
    for (n = 2; n < 20; n++) {                      // 计算后18个元素值
        fibonacci[n] = fibonacci[n - 2] + fibonacci[n - 1];
        // 分4行打印,按每行5个数打印输出,左对齐
        if (n % 5 == 0)
            printf("\n");
        printf("%-5d", fibonacci[n]);
    }
    printf("\n");
}
