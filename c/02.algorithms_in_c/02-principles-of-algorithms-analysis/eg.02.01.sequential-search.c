#include <stdio.h>
#define MAX 100
#define sa sizeof(a) / sizeof(a[0]) - 1
int inputArray(int *a) {
    int n;
    printf("Enter array size --> \n");
    if (scanf("%d", &n) != 1) {
        fprintf(stderr, "bad array size read - exiting \n");
        return -1;
    } else if (n <= 0 || n >= MAX) {
        fprintf(stderr, "%d: bad value - must be > 0 and less than %d\n", n,
                MAX);
        return -1;
    }
    printf("Enter the array: \n");
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &a[i]) != 1) {
            fprintf(stderr, "bad array entry read - exiting \n");
            return -1;
        }
    }
    return n;
}
int search(int a[], int v, int l, int r) {
    int i;
    for (i = l; i <= r; i++)
        if (v == a[i])
            return i;
    return -1;
}
int main(void) {
    int a[MAX] = {0}, n = 0, v, idx, i = 0;
    /*    n = inputArray(a);*/
    FILE *ptr = fopen("201.txt", "r");
    if (ptr == NULL) {
        printf("no such file.");
        return 0;
    }
    while (fscanf(ptr, "%d\n", &a[i]) == 1) {
        if (n > MAX - 1)
            break;
        n++;
        i++;
    }
    if (n < 0)
        return -1;
    printf("\nEnter the number to search: ");
    scanf("%d", &v);
    idx = search(a, v, 0, sa);
    if (idx > -1) {
        printf("\n%d is the %d th element in array.\n", v, idx);
    } else {
        printf("\n%d is not in the array.\n", v);
    }
    return 0;
}
