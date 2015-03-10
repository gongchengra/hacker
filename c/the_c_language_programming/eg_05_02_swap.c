#include <stdio.h>
void swap(int *px, int *py)
{
int temp;
/* interchange *px and *py */
temp = *px;
*px = *py;
*py = temp;
}
int main(void)
{
    int a = 4;
    int b = 5;
    printf("a = %d, b = %d \n", a, b);
    swap(&a,&b);
    printf("a = %d, b = %d", a, b);
    return 0;
}
