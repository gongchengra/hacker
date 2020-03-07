#include <stdio.h>
void display(int *p);
int main() {
    int *p;
    int a[][3] = {{15, 38, -52}, {-97, -85, 88}, {331, 457, -56}};
    p = a[0]; // 与p=&a[0][0];等效
    display(p);
    return 0;
}
void display(int *p) {
    int i;
    for (i = 0; i < 9; i++, ++p) {
/*        if (i != 0 && i % 3 == 0)*/
        if (i % 3 == 0)
            printf("\n");
        printf("%5d", *p);
    }
    printf("\n");
}
