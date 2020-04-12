/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : 72_insertion_sort.c
* Author : gongchengra@gmail.com
* Purpose :
* Creation Date : 2020-04-08
* Last Modified :
_._._._._._._._._._._._._._._._._._._._._.*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10
#define MAX 1000
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}
void randData(int a[], int len) {
    srand(time(NULL));
    for (int i = 0; i < len; i++) {
        a[i] = rand() % MAX;
        printf("%4d", a[i]);
    }
    printf("\n");
}
void printArr(int a[], int len) {
    for (int i = 0; i < len; i++) {
        printf("%4d", a[i]);
    }
    printf("\n");
}
void insertionSort(int a[], int len) {
    for (int i = 1; i < len; i++) {
        for (int j = i; j > 0 && a[j - 1] > a[j]; j--) {
            swap(&a[j - 1], &a[j]);
        }
    }
}
void insertionSort1(int a[], int len) {
    for (int i = 1; i < len; i++) {
        int x = a[i], j;
        for (j = i - 1; j >= 0 && a[j] > x; j--) {
            a[j + 1] = a[j];
        }
        a[j + 1] = x;
    }
}
void insertionSortR(int a[], int len) {
    if (len > 0) {
        insertionSortR(a, len - 1);
        int n = len - 1;
        int x = a[n], j;
        for (j = n - 1; j >= 0 && a[j] > x; j--) {
            a[j + 1] = a[j];
        }
        a[j + 1] = x;
    }
}
int main(int argc, char **argv) {
    int a[SIZE];
    randData(a, SIZE);
    insertionSortR(a, SIZE);
    printArr(a, SIZE);
    return 0;
}
