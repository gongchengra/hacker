#include <stdio.h>
void swap(int[]); // 数组原型使用“类型 []”的形式
int main() {
    int a[] = {23, 85};
    printf("In main:a[0]=%d, a[1]=%d\n", a[0], a[1]);
    swap(a); // 传递数组名
    printf("In main:a[0]=%d, a[1]=%d\n", a[0], a[1]);
}
/*void swap(int a[]) {*/
void swap(int *a) {
    int temp = a[0];
    a[0] = a[1];
    a[1] = temp;
    printf("In swap:a[0]=%d, a[1]=%d\n", a[0], a[1]);
}
