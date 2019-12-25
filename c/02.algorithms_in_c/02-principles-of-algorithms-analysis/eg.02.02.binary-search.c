#include <stdio.h>
#define MAX 100
#define sa sizeof(a) / sizeof(a[0]) - 1
int inputArray(int *a) {
    int n;
    printf("Enter array size --> \n");
    if (scanf("%d", &n) != 1) {
        fprintf(stderr, "bad array size read - exiting \n");
    } else if (n <= 0 || n >= MAX) {
        fprintf(stderr, "%d: bad value - must be > 0 and less than %d\n", n,
                MAX);
    }
    printf("Enter the array: \n");
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &a[i]) != 1) {
            fprintf(stderr, "bad array entry read - exiting \n");
        }
    }
    return n;
}
int search(int a[], int v, int l, int r) {
    while (r >= l) {
        int m = (l + r) / 2;
        if (v == a[m])
            return m;
        if (v < a[m])
            r = m - 1;
        else
            l = m + 1;
    }
    return -1;
}
int main(void) {
    int a[MAX] = {0}, n, v, idx;
    n = inputArray(a);
    printf("\nEnter the number to search: ");
    scanf("%d", &v);
    idx = search(a, v, 0, n);
    if (idx > -1) {
        printf("\n%d is the %d th element in array a.", v, idx);
    } else {
        printf("\n%d is not in the array a.", v);
    }
    return 0;
}
