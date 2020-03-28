#include <stdio.h> // 预编译命令
#define sa(a) sizeof(a)/sizeof(a[0])
/*or void Exch(int *a) {*/
void Exch(int a[], int s) {
    int c;
    /*    c = a[0];*/
    /*    a[0] = a[4];*/
    /*    a[4] = c;*/
    /*    c = a[1];*/
    /*    a[1] = a[3];*/
    /*    a[3] = c;*/
    for (int i = 0; i <= s / 2; i++) {
        c = a[i];
        a[i] = a[s - i - 1];
        a[s - i - 1] = c;
    }
}
void Display(int a[], int s) {
    int i;
    for (i = 0; i < s; i++)
        printf("%d ", a[i]);
    printf("\n");
}
int main() {
    int a[] = {1, 3, 5, 7, 9}, s = sa(a);
    Display(a, s);
    Exch(a, s);
    Display(a, s);
    return 0;
}
