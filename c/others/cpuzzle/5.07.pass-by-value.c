#include <stdio.h>
void swap(int, int); // 函数参数采用传数值方式
int main() {
    int a = 55, b = 66;
    swap(a, b);                            // 传数值
    printf("In main: a=%d, b=%d\n", a, b); // 返回主函数后
}
// 将变量作为参数，以传数值方式传递参数
void swap(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    printf("In swap: a=%d, b=%d\n", a, b); // 在被调函数里
}
