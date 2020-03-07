#include <stdio.h>
extern int a;
int b = 50;
void func1(void);
void func2(void);
int main() {
    int i;
    for (i = 1; i < 4; i++) {
        ++a;
        printf("%d\t", a);
        printf("%d\t", b++);
        func1();
        func2();
    }
}
int a = 10;
void func1() {
    ++a;
    printf("%d\t", a);
}
void func2() {
    int a = 500;
    int b = 25;
    ++a;
    printf("%d\t%d\n", a, ++b);
}
