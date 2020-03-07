#include <stdio.h>
void display(int[]);
void disp(int *);
int main() {
    int i = 0, sum = 0, a[] = {1, -2, 3, -4, 5};
    int b[] = {2, 4, 6, 8, 10}, *p;
    display(a);
    p = b;
    display(p);
    p = a;
    disp(p);
    disp(b);
    return 0;
}
void display(int a[]) {
    for (int i = 0; i < 5; i++)
        printf("%d ", *(a + i));
    printf("\n");
}
void disp(int *p) {
    for (int i = 0; i < 5; i++)
        printf("%d ", *(p + i));
    printf("\n");
}
