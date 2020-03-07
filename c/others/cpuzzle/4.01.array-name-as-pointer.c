#include <stdio.h>
int main() {
    int i, a[] = {1, 3, 5, 7, 8};
    *(a + 4) = 86; // 使用数组名a作为数组第1个元素的指针
    for (i = 0; i < 5; ++i)
        printf("%d %d ", a[i], *(a + i)); // 交替使用两种方式输出
    printf("\n");
}
