/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : eg_03_05_mem.c
* Author : gongchengra@gmail.com
* Purpose :
* Creation Date : 2020-04-14
* Last Modified :
_._._._._._._._._._._._._._._._._._._._._.*/
#include <stdio.h>
void shellsort(int arr[], int len) {
    int gap, i, j, tmp;
    for (gap = len >> 1; gap > 0; gap >>= 1) {
        for (i = gap; i < len; i++) {
            for (j = i - gap; j >= 0 && arr[j] > arr[j + gap]; j -= gap) {
                tmp = arr[j];
                arr[j] = arr[j + gap];
                arr[j + gap] = tmp;
            }
        }
    }
}
int main(int argc, char **argv) {
    int a[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    shellsort(a, sizeof(a) / sizeof(int));
    for (int i = 0; i < sizeof(a) / sizeof(int); i++) {
        printf("%4d", a[i]);
    }
    printf("\n");
}
