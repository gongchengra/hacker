#include <stdio.h>
int main() {
    int a[3][3], i, j, *p;
    p = a[0];
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            p[i * 3 + j] = i * 3 + j + 1;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++)
            printf("%d ", *(p + i * 3 + j));
        printf("\n");
    }
    printf("\n");
    printf("%d ", p[0]);
    p = &a[2][2];
    printf("%d\n", p[0]);
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++)
            printf("%d ", *(p - i * 3 - j));
        printf("\n");
    }
    // 使用的是偏移量，*p仍然是最后一个元素
    printf("%d\n", *p);
    // 使用最后一个元素的地址重新赋值
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            p[-i * 3 - j] = 99 - i * 3 - j; // 等效于*(p-i*3-j)=99-i*3-j;
    // 重新赋值
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++)
            printf("%d ", *(p - i * 3 - j)); // 等效于printf( "%d ",p[-i*3-j]);
        printf("\n");
    }
    printf("\n");
    // 逆向输出
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++, --p)
            printf("%d ", *p);
        printf("\n");
    }
    ++p;                // 越界，调整指向第1个元素的地址
    printf("%d\n", *p); // 输出第1个元素
    return 0;
}
