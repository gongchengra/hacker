/*#include <stdio.h>*/
/*void display(int[], int *);*/
/*void display(int a[], const int *p) {*/
/*    int i = 0;*/
/*    for (p=a; i < 5; i++)*/
/*        printf("%d ", *p+i);*/
/*    printf("\n");*/
/*}int main() {*/
/*    int i = 0, sum = 0, a[] = {1, -2, 3, -4, 5}, *p;*/
/*    int b[] = {2, 4, 6, 8, 10};*/
/*    p=a;*/
/*    display(a, p);*/

/*    p=b;*/
/*    display(b, p);*/
/*    for (i = 0; i < 5; i++, p++)*/
/*        sum = sum + *p;*/
/*    printf("sum=%d\n", sum);*/
/*    return 0;*/
/*}*/
#include <stdio.h>
void display(int[]);
int main() {
    int i = 0, sum = 0, a[] = {1, -2, 3, -4, 5}, *p = a;
    int b[] = {2, 4, 6, 8, 10};
    display(a);
    display(b);
    for (i = 0; i < 5; i++)
        sum = sum + b[i];
    printf("sum=%d\n", sum);
    return 0;
}
void display(int a[]) {
    for (int i = 0; i < 5; i++)
        printf("%d ", a[i]);
    printf("\n");
}
