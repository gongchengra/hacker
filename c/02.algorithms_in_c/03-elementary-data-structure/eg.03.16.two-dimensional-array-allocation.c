#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int **malloc2d(int r, int c) {
    int i;
    int **t = malloc(r * sizeof(int *));
    for (i = 0; i < r; i++)
        t[i] = malloc(c * sizeof(int));
    return t;
}
int main(void) {
    int r, c, **a;
    printf("Enter n: ");
    scanf("%d", &r);
    printf("Enter m: ");
    scanf("%d", &c);
    a = malloc2d(r, c);
    srand(time(NULL));
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++) {
            a[i][j] = rand() % 1000;
            printf("%5d", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
