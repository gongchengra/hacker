#include <stdio.h>
#include <stdlib.h>
void dive(double *);
int main() {
    double a[3][2] = {0, 0};
    double *p = a[0];
    for (;;) {
        printf("输入第1个复数：");
        scanf("%lf%lfi", &p[0], &p[1]);
        printf("输入第2个复数：");
        scanf("%lf%lfi", &p[2], &p[3]);
        if ((p[0] == 0) && (p[1] == 0) && (p[2] == 0) && (p[3] == 0)) {
            printf("再见！\n");
            return 0;
        }
        if ((p[0] == 0) && (p[1] == 0)) {
            printf("被除数为0，本次作废，继续输入。\n");
            continue;
        }
        dive(p);
        if (p[2] == -1)
            continue;
        printf("\n计算结果：%lf%+lfi\n", p[4], p[5]);
    }
}
void dive(double *p) {
    double d;
    if ((p[2] == 0) && (p[3] == 0)) {
        printf("除数为0，本次作废，继续输入。\n");
        p[2] = -1;
        return;
    }
    d = p[2] * p[2] + p[3] * p[3];
    p[4] = (p[0] * p[2] + p[1] * p[3]) / d;
    p[5] = (p[1] * p[2] - p[0] * p[3]) / d;
    return;
}
