/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : 69_selection_sort.c
* Author : gongchengra@gmail.com
* Purpose :
* Creation Date : 2020-04-07
* Last Modified :
_._._._._._._._._._._._._._._._._._._._._.*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10
#define MAX 100
void swap(int *a, int *b) {
    /*    *a = *a + *b;*/
    /*    *b = *a - *b;*/
    /*    *a = *a - *b;*/
    int t = *a;
    *a = *b;
    *b = t;
}
void randData(int arr[], int len){
    srand(time(NULL));
    for (int i = 0; i < len; i++) {
        arr[i] = rand() % MAX;
        printf("%4d", arr[i]);
    }
    printf("\n");
}
void selectionSort(int arr[], int len){
    int jmin;
    for (int i = 0; i < len - 1; i++) {
        jmin = i;
        for (int j = i + 1; j < len; j++) {
            if (arr[j] < arr[jmin]) {
                swap(&arr[j], &arr[jmin]);
            }
        }
    }
}
void printArray(int arr[], int len){
    for (int i = 0; i < len; i++) {
        printf("%4d", arr[i]);
    }
}
int main(int argc, char **argv) {
    int arr[SIZE];
    randData(arr, SIZE);
    selectionSort(arr, SIZE);
    printArray(arr, SIZE);
}
