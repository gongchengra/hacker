#include <stdio.h>

int main(void)
{
    int  i, j, k=0;
    int  iArr[4][5];

    //输出iArr[i,j]数组的地址
    for (i=0; i<4; i++) {
        for (j=0; j<5; j++) {
            iArr[i][j] = k++;
            printf("iArr[%d,%d]=%2d  &iArr[%d,%d]=%p\n", 
                i, j, iArr[i][j], i, j, &iArr[i][j]);
        }
        printf("\n");
    }

    return 0;
}
