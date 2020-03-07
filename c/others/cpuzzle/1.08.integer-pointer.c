#include <stdio.h>
int main() {
    int a = 65, *p;
    p = &a;
    printf("a的值等于%d, a的首地址是%p, p指向的地址是%p。\n", a, &a, p);
    printf("通过名字使用%d, 通过p内的地址%p使用%d。\n", a, p, *p);
    printf("p指向的地址为%p, 存放p的地址是%p。\n", p, &p);
    return 0;
}
