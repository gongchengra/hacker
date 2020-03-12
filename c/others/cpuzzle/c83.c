#include "c83.h"
const int SIZE = 5;
int main() {
    double *x, *y, res, a[SIZE] = {0.0};
    int i;
    if ((x = init(SIZE)) == NULL)
        return 0;
    readin(x);
    product(x, &res, SIZE);
    printf("Their product is: %10.2f\n", res);
    printf("\tx:\n");
    for (i = 0; i < SIZE; i++) {
        if (i == 5)
            printf("\n");
        printf("%10.2f ", *(x + i));
    }
    printf("\n\ta:\n");
    sort(x, a, SIZE);
    for (i = 0; i < SIZE; i++) {
        if (i == 5)
            printf("\n");
        printf("%10.2f ", *(a + i));
    }
    printf("\n\ty:");
    if ((y = init(SIZE)) == NULL)
        return 0;
    for (i = 0; i < SIZE; i++, y++) // 扩大10倍并存入内存
        *y = a[i] * SIZE;
    for (--y, i = SIZE; i > 0; i--, y--) {
        if (i == 5)
            printf("\n");
        printf("%10.2f ", *y);
    }
    ++y;
    free(y);
    free(x);
    printf("\n");
    return 0;
}
double *init(int n) { return (double *)malloc(n * sizeof(double)); }
void readin(double *a) {
    int i;
    printf("Please enter %d value:\n", SIZE);
    for (i = 0; i < SIZE; i++)
        scanf("%lf", a + i);
}
void product(double *addr, double *result, int n) {
    for (n--, *result = *(addr + n); --n >= 0; *result *= *(addr + n))
        ; // 空语句
}
void sort(double *x, double a[], int n) {
    int i, j, pick;
    for (i = 0; i < n; i++)
        a[i] = *(x + i);
    for (i = 0; i < (n - 1); ++i) {
        pick = i;
        for (j = i + 1; j < n; j = j + 1) {
            if (a[j] < a[pick])
                pick = j;
        }
        swap(&a[pick], &a[i]);
    }
}
void swap(double *p1, double *p2) {
    double temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}
