#include <stdio.h>
int main() {
    int i, a[3][3] = {2, 4, 6};
    // wrong a[3][1] = 25;
    a[2][1] = 25;
    // wrong for (i = 0; i <= 3; i++)
    for (i = 0; i < 3; i++)
        printf("%d ", a[i][1]);
}
