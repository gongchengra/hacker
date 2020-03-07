#include <stdio.h>  // 预编译命令
int Jump(int, int); // 声明有被调用函数
int main() {
    int s = 0, y = 0, sum = 0;
    printf("请输入石柱数s=");
    scanf("%d", &s);
    printf("请输入荷叶数y=");
    scanf("%d", &y);
    sum = Jump(s, y); // 调用函数求解
    printf("Jump(%d,%d)=%d\n", s, y, sum);
}
int Jump(int r, int z) {
    return r == 0 ? z + 1 : 2 * Jump(r - 1, z);
    /*    int k = 0;*/
    /*    if (r == 0)    // 如果 r 为 0 ,则为直接可解结点,*/
    /*        k = z + 1; // 直接可解结点, k 值为 z + 1*/
    /*    else           // 如果r不为0,则要调用Jump( r-1, z )*/
    /*        k = 2 * Jump(r - 1, z);*/
    /*    return (k); // 将 k 的值返回给 Jump ( s , y )*/
}
