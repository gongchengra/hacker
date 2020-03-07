#include <stdio.h>
void swap(int *, int *);
int main() {
    int a = 23, b = 85;
    int *p1 = &a, *p2 = &b; // 多余的方式
    swap(p1, p2);           // 可以直接使用swap(&a,&b);
    printf("Now a=%d, b=%d\n", a, b);
}
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    printf("In swap:a=%d, b=%d\n", *a, *b);
}
