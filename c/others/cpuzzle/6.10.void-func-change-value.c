#include <stdio.h> // 预编译命令
void Exch(int *);
void Display(int[]);
int main() {
    int a[] = {1, 3, 5, 7, 9};
    Display(a);
    Exch(a);
    Display(a);
    return 0;
}
/*or void Exch(int *a) {*/
void Exch(int a[]) {
    int c;
    c = a[0];
    a[0] = a[4];
    a[4] = c;
    c = a[1];
    a[1] = a[3];
    a[3] = c;
}
void Display(int a[]) {
    int i;
    for (i = 0; i < 5; i++)
        printf("%d ", a[i]);
    printf("\n");
}
