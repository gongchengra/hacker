#include <stdio.h>
int main() {
    int x = 256, y = 386, *p = &x;
    void *vp = &x; // void指针指向x
    printf("%p,%p,%d\n", vp, p, x);
    vp = &y;       // void指针改为指向y
    p = (int *)vp; // 强制将void指针赋值给整型指针
    printf("%p,%p,%d\n", vp, p, *p);
    return 0;
}
