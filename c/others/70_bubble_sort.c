/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : 70_bubble_sort.c
* Author : gongchengra@gmail.com
* Purpose :
* Creation Date : 2020-04-08
* Last Modified :
_._._._._._._._._._._._._._._._._._._._._.*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10
#define MAX 100
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}
void randData(int arr[], int len) {
    srand(time(NULL));
    for (int i = 0; i < len; i++) {
        arr[i] = rand() % MAX;
/*        arr[i] = len -i;*/
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
void bubbleSort(int arr[], int len) {
    int swapFlag;
    do {
        swapFlag = 0;
        for (int i = 1; i < len; i++) {
            if (arr[i - 1] > arr[i]) {
                swap(&arr[i - 1], &arr[i]);
                swapFlag = 1;
                printArray(arr, SIZE);
            }
        }
    } while (swapFlag == 1);
}
void bubbleSort1(int arr[], int len) {
    int swapFlag;
    do {
        swapFlag = 0;
        for (int i = 1; i < len; i++) {
            if (arr[i - 1] > arr[i]) {
                swap(&arr[i - 1], &arr[i]);
                swapFlag = 1;
                printArray(arr, SIZE);
            }
        }
        len--;
    } while (swapFlag == 1);
}
void bubbleSort2(int arr[], int len) {
    int swapFlag;
    do {
        int nLen = 0;
        for (int i = 1; i < len; i++) {
            if (arr[i - 1] > arr[i]) {
                swap(&arr[i - 1], &arr[i]);
                nLen = i;
                printArray(arr, SIZE);
            }
        }
        len = nLen;
    } while (len > 1);
}
int main(int argc, char **argv) {
    int arr[SIZE];
    printf("v1:\n");
    randData(arr, SIZE);
    bubbleSort(arr, SIZE);
    printArray(arr, SIZE);
    printf("v2:\n");
    randData(arr, SIZE);
    bubbleSort1(arr, SIZE);
    printArray(arr, SIZE);
    printf("v3:\n");
    randData(arr, SIZE);
    bubbleSort2(arr, SIZE);
    printArray(arr, SIZE);
}
