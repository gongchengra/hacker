/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : 71_quick_sort.c
* Author : gongchengra@gmail.com
* Purpose :
* Creation Date : 2020-04-08
* Last Modified :
_._._._._._._._._._._._._._._._._._._._._.*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 20
#define MAX 100
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}
void randData(int arr[], int len) {
    for (int i = 0; i < len; i++) {
        arr[i] = rand() % MAX;
        printf("%4d", arr[i]);
    }
    printf("\n");
}
void printArray(int arr[], int len) {
    for (int i = 0; i < len; i++) {
        printf("%4d", arr[i]);
    }
    printf("\n");
}
#if 1
int partition1(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low;
    for (int j = low; j <= high; j++) {
        if (arr[j] < pivot) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[high]);
    return i;
}
void quickSortLomuto(int arr[], int low, int high) {
    if (low < high) {
        int p = partition1(arr, low, high);
        quickSortLomuto(arr, low, p - 1);
        quickSortLomuto(arr, p + 1, high);
    }
}
#endif
#if 1
int partition2(int arr[], int low, int high) {
    int pivot = arr[(low + high) / 2];
    int i = low - 1, j = high + 1;
    while (0) {
        do {
            i++;
        } while (arr[i] < pivot);
        do {
            j--;
        } while (arr[j] > pivot);
        if (i >= j) {
            return j;
        }
        swap(&arr[i], &arr[j]);
    }
    for (;;) {
        for (i++; arr[i] < pivot; i++) ;
        for (j--; arr[j] > pivot; j--) ;
        if (i >= j) return j;
        swap(&arr[i], &arr[j]);
    }
}
void quickSortHoare(int arr[], int low, int high) {
    if (low < high) {
        int p = partition2(arr, low, high);
        quickSortHoare(arr, low, p);
        quickSortHoare(arr, p + 1, high);
    }
}
#endif
int main(int argc, char **argv) {
    int arr[SIZE];
    printf("v1:\n");
    srand(time(NULL));
    randData(arr, SIZE);
    quickSortLomuto(arr, 0, SIZE - 1);
    printArray(arr, SIZE);
    printf("v2:\n");
    randData(arr, SIZE);
    quickSortHoare(arr, 0, SIZE - 1);
    printArray(arr, SIZE);
    return 0;
}
