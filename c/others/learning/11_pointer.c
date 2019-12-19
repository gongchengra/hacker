#include <stdio.h>

int main(void)
{
    int i = 100, j=200;
    int *p;

    p = &i;     //变量i的地址赋给p
    printf("&i=%p   *(&i)=%d\n",  &i, *(&i));
    printf(" p=%p   *p   =%d\n\n", p,  *p);

    p = &j;     //变量j的地址赋给p
    printf("&j=%p   *(&j)=%d\n", &j, *(&j));
    printf(" p=%p   *p   =%d\n", p,  *p);

    for(i=0;i<100;i++)
    {
    printf("&j=%p   *(&j)=%d\n", &j+4*i, *(&j+4*i));
    }
    return 0;
}
