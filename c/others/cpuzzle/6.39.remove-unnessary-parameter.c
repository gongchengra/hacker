#include <stdio.h>
void swap(int *, int *);
int main() {
    int a = 23, b = 85;
    /*    int *p1 = &a, *p2 = &b;*/
    /*    swap(p1, p2); // 可以直接使用swap(&a,&b);*/
    printf("%d %d\n", a, b);
    swap(&a, &b);
    printf("%d %d\n", a, b);
}
void swap(int *P1, int *P2) {
    /*    int x = 5, *temp = &x;*/
    int temp;
    temp = *P1;
    *P1 = *P2;
    *P2 = temp;
}
