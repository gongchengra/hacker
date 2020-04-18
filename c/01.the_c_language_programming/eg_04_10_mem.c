/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : eg_04_10_mem.c
* Author : gongchengra@gmail.com
* Purpose :
* Creation Date : 2020-04-16
* Last Modified :
_._._._._._._._._._._._._._._._._._._._._.*/
#include <stdio.h>
#if 1
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}
void qSort(int arr[], int lo, int hi) {
    if (lo < hi) {
        swap(&arr[lo], &arr[(lo + hi) / 2]);
        int last = lo;
        for (int i = lo + 1; i <= hi; i++) {
            if (arr[i] < arr[lo]) {
                swap(&arr[i], &arr[++last]);
            }
        }
        swap(&arr[lo], &arr[last]);
        qSort(arr, lo, last - 1);
        qSort(arr, last + 1, hi);
    }
}
#endif
#if 0
// not working
void swap(void *v[], int i, int j) {
    printf("i=%d, j=%d\n", i, j);
    printf("%d, %d\n", (int)v[i], (int)v[j]);
    void *tmp;
    tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
    printf("i=%d, j=%d\n", i, j);
    printf("%d, %d\n", (int)v[i], (int)v[j]);
}
void qSort(void *arr, int lo, int hi) {
    if (lo < hi) {
        swap(arr, lo, ((lo + hi) / 2));
        int last = lo;
        for (int i = lo + 1; i <= hi; i++) {
            if (arr[i] < arr[lo]) {
                swap(arr, i, (++last));
            }
        }
        swap(arr, lo, last);
        qSort(arr, lo, last - 1);
        qSort(arr, last + 1, hi);
    }
}
#endif
#if 0
void qSort(int arr[], int lo, int hi) {
    if (lo < hi) {
        int pivot = arr[(lo + hi) / 2];
        int i = lo - 1, j = hi + 1;
        for (;;) {
            for (i++; arr[i] < pivot; i++)
                ;
            for (j--; arr[j] > pivot; j--)
                ;
            if (i >= j) {
                break;
            }
            swap(&arr[i], &arr[j]);
        }
        qSort(arr, lo, j);
        qSort(arr, j + 1, hi);
    }
}
#endif
#include <assert.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define size 10
#define max 1000
#define digit (int)(log10(max) + 1)
int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }
int main(int argc, char **argv) {
    int *arr, test[size];
    srand(time(NULL));
    arr = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        test[i] = arr[i] = rand() % max;
        printf("%*d", digit, arr[i]);
    }
    printf("\n");
    qSort(arr, 0, size - 1);
    qsort(test, size, sizeof(int), cmp);
    for (int i = 0; i < size; i++) {
        printf("%*d", digit, arr[i]);
    }
    printf("\n");
    for (int i = 0; i < size; i++) {
        printf("%*d", digit, test[i]);
        assert(arr[i] == test[i]);
    }
    printf("\n");
#if 0
#endif
    return 0;
}
