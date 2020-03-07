#include <stdio.h>
int BinarySearch(const int A[], int Key, int n); // 声明查找函数原型
int main() {
    int Key, b;
    const int a[] = {11, 12, 13, 17, 18,
                     22, 24, 45, 48, 80}; // 常量数组，只能使用不能改变
    printf("输入查找关键字：");
    scanf("%d", &Key);
    b = BinarySearch(a, Key, 10);
    if (b != -1)
        printf("关键字在数组中为a[%d]\n", b);
    else
        printf("数组中无此数！\n");
}
// 线性查找函数
// n：给定数组的有效长度
// Key：查找关键字
int BinarySearch(const int A[], int Key, int n) {
    int middle = 0;
    int low = 0;   // 初始化为数组a的第一个元素的下标
    int hight = n; // 初始化为数组a的最后一个元素的下标
    while (low <= hight) {
        middle = (low + hight) / 2;
        if (A[middle] == Key)
            return middle;
        else if (A[middle] > Key)
            hight = hight - 1; // 落在下部，上限减1
        else
            low = middle + 1; // 落在上部，下限加1
    }
    return -1;
}
