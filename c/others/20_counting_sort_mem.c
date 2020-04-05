#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define max 100
void print_arr(int arr[], int len) {
    for (int i = 0; i < len; i++) {
        printf("%4d", arr[i]);
    }
    printf("\n");
}
void counting_sort(int arr[], int sorted_arr[], int len) {
    int *count_arr = (int *)malloc(sizeof(int) * max);
    for (int i = 0; i < max; i++) {
        count_arr[i] = 0;
    }
    for (int j = 0; j < len; j++) {
        count_arr[arr[j]]++;
    }
    for (int k = 0, r = 0; k < max; k++) {
        if (count_arr[k] > 0) {
            for (sorted_arr[r] = k; count_arr[k] > 0; count_arr[k]--) {
                sorted_arr[++r] = k;
            }
        }
    }
    free(count_arr);
}
int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }
int main(int argc, char *argv[]) {
    int len = 30;
    int arr[len], sorted_arr[len];
    srand(time(0));
    for (int i = 0; i < len; i++) {
        arr[i] = rand() % max;
    }
    print_arr(arr, len);
    counting_sort(arr, sorted_arr, len);
    print_arr(sorted_arr, len);
    qsort((void *)arr, len, sizeof(arr[0]), cmp);
    print_arr(arr, len);
}
