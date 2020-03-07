#include <stdio.h>
union s {
    int a;
    char s1[4];
} uc;
int main() {
    int i = 0;
    uc.a = 0x12345678;
    printf("%x\n", uc.a);
    for (i = 0; i < 4; i++)
        printf("%p %x\n", &uc.s1[i], uc.s1[i]);
    return 0;
}
