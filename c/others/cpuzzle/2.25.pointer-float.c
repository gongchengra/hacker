#include <math.h>
#include <stdio.h>
#include <stdlib.h>
int const SIZE = 5;
int main() {
    float *pf, *temppf, *min, temp, sum = 0.0;
    if ((min = temppf = pf = (float *)malloc(SIZE * sizeof(float))) == NULL)
        printf("内存分配错误\n");
    else {
        for (; temppf - pf < SIZE; temppf++) {
            scanf("%10f", &temp);
            *temppf = temp;
        }
        for (temppf--; temppf >= pf; temppf--) {
            min = (*min > *temppf) ? temppf : min;
            sum += *temppf;
        }
    }
    printf("和是%5.2f, 最小值是%5.2f\n", sum, *min);
    free(pf);
}
