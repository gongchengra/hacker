#include <stdio.h>
void display(int[]);
void disp(int *);
int main() {
    int i = 0, sum = 0, a[2][3] = {1, -2, 3, -4, 5, 7};
    int b[2][3] = {2, 4, 6, 8, 10, 12}, *p;
    display(a[0]);
    p = b[0];
    display(p);
    p = a[0];
    disp(p);
    disp(b[0]);
    return 0;
}
void display(int a[]) {
    for (int i = 0; i < 6; i++)
        printf("%d ", *(a + i));
    printf("\n");
}
void disp(int *p) {
    for (int i = 0; i < 6; i++)
        printf("%d ", p[i]);
    printf("\n");
}
