#include <stdio.h>
union uda {
    int num;
    unsigned char str[4];
    float f;
} u;
int main() {
    int i = 0;
    u.f = 2.5;
    printf("f = %f\n", u.f);
    for (i = 0; i < 4; i++)
        printf("str[%d] = %#x\n", i, u.str[i]);
    printf("num= %#x\n", u.num);
    u.f = 0.0;
    printf("f = %f\n", u.f);
    for (i = 0; i < 4; i++)
        printf("str[%d] = %#x\n", i, u.str[i]);
    u.num = 0x40200000;
    printf("num= %#x\n", u.num);
    printf("f = %f\n", u.f);
    for (i = 0; i < 4; i++)
        printf("str[%d] = %#x\n", i, u.str[i]);
}
