#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}
void max_heapify(int arr[], int start, int end) {
    int dad = start;
    int sonLeft = dad * 2 + 1;
    int sonRight = dad * 2 + 2;
    if (sonLeft < end && arr[sonLeft] > arr[dad]) {
        dad = sonLeft;
    }
    if (sonRight < end && arr[sonRight] > arr[dad]) {
        dad = sonRight;
    }
    if (dad != start) {
        swap(&arr[dad], &arr[start]);
        max_heapify(arr, dad, end);
    }
}
void heap_sort(int arr[], int len) {
    int i;
    for (i = len / 2 - 1; i >= 0; i--) {
        max_heapify(arr, i, len);
    }
    for (i = len - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        max_heapify(arr, 0, i);
    }
}
int main(int argc, char *argv[]) {
    int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int len = (int)sizeof(arr) / sizeof(arr[0]);
    heap_sort(arr, len);
    for(int i =0; i< len; i++){
        printf("%4d", arr[i]);
    }
    return 0;
}
