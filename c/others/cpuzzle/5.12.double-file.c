#include "DoubleFile.h" // 注意使用双引号包含DoubleFile.h
int main()              // 主函数
{
    int a, b, x;
    a = 2;
    b = 3;
    x = NUM * max(a, b);
    printf("%d\n", x);
    return 0;
}
int max(int m1, int m2) {
    if (m1 > m2)
        return m1 + NUM;
    else
        return m2 + NUM;
}
