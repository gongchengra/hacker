#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 23
int cmp(const void *i, const void *j) { return (*(int *)i - *(int *)j); }
int min(int x, int y) { return x < y ? x : y; }
void print_arr(int arr[], int len) {
    for (int i = 0; i < len; i++) {
        printf("%5d", arr[i]);
    }
    printf("\n");
}
void merge_sort(int arr[], int len) {
    int *a = arr;
    int *b = (int *)malloc(len * sizeof(int));
    for (int seg = 1; seg < len; seg += seg) {
        for (int start = 0; start < len; start += seg * 2) {
            int low = start, mid = min(start + seg, len),
                high = min(start + seg * 2, len);
            int k = low;
            int start1 = low, end1 = mid;
            int start2 = mid, end2 = high;
            while (start1 < end1 && start2 < end2) {
                b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
            }
            while (start1 < end1) {
                b[k++] = a[start1++];
            }
            while (start2 < end2) {
                b[k++] = a[start2++];
            }
        }
        int *tmp = a;
        a = b;
        b = tmp;
    }
    for (int i = 0; i < len; i++)
        arr[i] = a[i];
    b = a;
    free(b);
}
int main() {
    int i, a[N], arr[N];
    srand(time(NULL));
    for (i = 0; i < N; i++) {
        arr[i] = a[i] = 1000 * (1.0 * rand() / RAND_MAX);
    }
    print_arr(a, N);
    mergesort(a, N, sizeof(int), cmp);
    print_arr(a, N);
    /*    swap(&a[0], &a[1]);*/
    /*    print_arr(a, N);*/
    merge_sort(arr, N);
    print_arr(arr, N);
}
