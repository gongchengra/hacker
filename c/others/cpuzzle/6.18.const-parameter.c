#include <stdio.h>
void swap(int *, const int);
int main() {
    int a = 23, b = 85;
    printf("In main:a=%d, b=%d\n", a, b);
    swap(&a, b);
    printf("In main:a=%d, b=%d\n", a, b);
}
void swap(int *a, const int b) {
    *a = *a + b;
    printf("In swap:a=%d, b=%d\n", *a, b);
}
