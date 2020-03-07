#include <stdio.h>
int main() {
    int a = 456;
    int *p;
    printf("指针没有初始化：\n");
    printf("%p,%p\n", p, &p);
    p = NULL;
    printf("指针初始化为NULL：\n");
    printf("%p,%p\n", p, &p);
}
