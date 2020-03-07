#include <stdio.h>
void display(int (*a)[3]);
int main() {
    int a[][3] = {{15, 38, -52}, {-97, -85, 88}, {331, 457, -56}};
    display(&a[0]); // 等效display(a);
    return 0;
}
void display(int (*a)[3]) {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++)
            printf("%5d", a[i][j]);
        printf("\n");
    }
    printf("\n");
}
