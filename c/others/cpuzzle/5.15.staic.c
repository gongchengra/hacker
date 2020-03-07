#include <stdio.h>
int max(int, int);
int c;
int main() {
    {
        int a = 45, b = 98;
        static int sum;
        sum = max(45, 98);
        a += b;
        {
            int a[] = {1, -2, 3, -4, 5}, i = 0;
            static int sum;
            for (i = 0; i < 5; i++)
                if (a[i] < 0)
                    c = c + a[i];
                else
                    sum = sum + a[i];
            printf("正数和=%d,负数和=%d\n", sum, c);
        }
        c = max(a, sum);
        printf("max=%d\n", c);
        c = a + b + sum;
    }
    printf("总和=%d\n", c);
    return 0;
}
int max(int a, int b) {
    if (a < b)
        return b;
    else
        return a;
}
