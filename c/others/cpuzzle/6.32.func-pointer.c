#include <stdio.h>
double f1(double x);
double f2(double x);
#define STEP 0.1
int main() {
    int i;
    double x, (*p)(double); // double (*p)(double)与double (*p)( )等效
    for (i = 0; i < 2; i++) {
        printf("第%d个方程：\n", i + 1);
        if (i == 0)
            /*          wrong  p = f1(x);*/
            p = f1;
        else
            /*          wrong  p = f2(x);*/
            p = f2;
        for (x = -1; x <= 1; x += STEP)
            printf("%f\t%f\n", x, (*p)(x));
    }
    return 0;
}
// 函数 f1
double f1(double x) { return (x * x * x - 5 * x + 6); }
// 函数f2
double f2(double x) { return (x * x - 3 * x); }
