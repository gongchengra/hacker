/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : 75_shell_sort.c
* Author : gongchengra@gmail.com
* Purpose :
* Creation Date : 2020-04-14
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
void shellSort(int arr[], int n) {
    int i, j, tmp, gap;
    for (gap = n >> 1; gap > 0; gap >>= 1) {
        for (i = gap; i < n; i++) {
            tmp = arr[i];
            for (j = i - gap; j >= 0 && arr[j] > tmp; j -= gap) {
                arr[j + gap] = arr[j];
            }
            arr[j + gap] = tmp;
        }
    }
}
int main(int argc, char **argv) {
    int a[SIZE];
    randData(a, SIZE);
    shellSort(a, SIZE);
    printArr(a, SIZE);
    return 0;
}
