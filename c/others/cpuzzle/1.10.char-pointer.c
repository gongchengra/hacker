#include <stdio.h>
int main() {
    char a[] = "We are here! Where are you?", b[88], *p;
    int i = 0;
    p = b; // 数组b的首地址作为右值赋给左值p
    /*    while ((b[i] = a[i]) != '\0') // 数组a的每个元素值作为右值*/
    while ((p[i] = a[i]) != '\0') // 数组a的每个元素值作为右值
        i++;
    printf("%s", a);
    printf("\n");
    printf("%s", b);
    printf("\n");
    printf("%d", i);
}
