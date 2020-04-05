/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name :
* Author : gongchengra@gmail.com
* Purpose :
* Creation Date : 2016-05-31
* Last Modified :
_._._._._._._._._._._._._._._._._._._._._.*/
#include <stdio.h>
#include <stdlib.h>
void print_arr(int arr[]){
    for(int i=0;i< 10;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void swap(int *a, int *b, int arr[]) {
    printf("swap %d %d\n", *a, *b);
    print_arr(arr);
    int temp = *b;
    *b = *a;
    *a = temp;
}
void max_heapify(int arr[], int start, int end) {
    //建立父節點指標和子節點指標
    int dad = start;
    int son = dad * 2 + 1;
    while (son < end) { //若子節點指標在範圍內才做比較
        if (son + 1 < end &&
            arr[son] < arr[son + 1]) //先比較兩個子節點大小，選擇最大的
            son++;
        if (arr[dad] >
            arr[son]) //如果父節點大於子節點代表調整完畢，直接跳出函數
            return;
        else { //否則交換父子內容再繼續子節點和孫節點比較
            swap(&arr[dad], &arr[son], arr);
            dad = son;
            son = dad * 2 + 1;
        }
    }
}
void heap_sort(int arr[], int len) {
    int i;
    //初始化，i從最後一個父節點開始調整
    for (i = len / 2 - 1; i >= 0; i--)
        max_heapify(arr, i, len);
    //先將第一個元素和已排好元素前一位做交換，再從新調整，直到排序完畢
    for (i = len - 1; i > 0; i--) {
        swap(&arr[0], &arr[i], arr);
        max_heapify(arr, 0, i);
    }
}
int main() {
/*    int arr[] = {3, 5, 3, 0, 8, 6, 1, 5, 8, 6, 2, 4, 9, 4, 7,*/
/*                 0, 1, 8, 9, 7, 3, 1, 2, 5, 9, 7, 4, 0, 2, 6};*/
    int arr[] = {9,8,7,6,5,4,3,2,1,0};
    int len = (int)sizeof(arr) / sizeof(*arr);
    printf("%d\n", len);
    heap_sort(arr, len);
    int i;
    for (i = 0; i < len; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
