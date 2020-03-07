#include <stdio.h>
/*void display(const union data);*/
union data {
    int a[10];
    int b[2][5];
};
int main() {
    union data ab;
    int i;
    for (i = 0; i < 10; i++) // 置入21 22 23 24 25 26 27 28 29 30
        ab.a[i] = 21 + i;
/*    display(ab); // 输出21 22 23 24 25 26 27 28 29 30*/
}
/*void display(const union data a) {*/
/*    int i, j;*/
/*    for (i = 0; i < 2; i++)*/
/*        for (j = 0; j < 5; j++)*/
/*            printf("%3d", a.b[i][j]);*/
/*    printf("\n");*/
/*}*/
