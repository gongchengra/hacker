#include <stdio.h>
int max(int, int);
int c = 108;
int main() {
    {
        int a = 45, b = 98, c = 0;
        c = max(45, 98);
        {
            int c = 0, i = 0;
            for (; i < 11; i++)
                c = c + i;
            c *= c;
            c = max(c, 98);
            printf("max=%d\n", c);
        }
        printf("max=%d\n", c);
        c = max(a, -c);
        printf("max=%d\n", c);
    }
    printf("max=%d\n", c);
    return 0;
}
int max(int a, int b) {
    static int c;
    if (a < b)
        c = b;
    else
        c = a;
    return c;
}
