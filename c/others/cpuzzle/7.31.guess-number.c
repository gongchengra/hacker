#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int answer(int, int); // 声明调用函数原型
int main() {
    int n = 0;                        // 猜的次数
    int num;                          // 猜的整数
    int A;                            // 随机的整数
    srand((unsigned int)time(NULL)); // 随机数种子
    A = rand() % 100 + 1;             // 产生一个1~100之间的随机整数
    printf("数目在1和100之间，你能猜到吗？试试吧？\n");
    do {
        n++;
        printf("请你猜数!\n");
        scanf("%d", &num); // 输入猜的数
    } while (answer(num, A) != 0);
    printf("你猜了%d次!\n", n);
    return 0;
}
int answer(int num, int A) {
    if (num == A) {
        printf("很好，你猜中了!\n");
        return 0;
    } else if (num > A) {
        printf("你猜大了，请重猜!\n");
        return 1;
    } else {
        printf("你猜小了，请重猜!\n");
        return 2;
    }
}
