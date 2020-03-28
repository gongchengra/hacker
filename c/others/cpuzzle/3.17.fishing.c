#include <stdio.h>
void solution1() {
    int fish[6] = {1, 1, 1, 1, 1, 1}; // 记录每人醒来后看到的鱼数
    int i = 0;
    do {
        fish[5] = fish[5] + 5; // 让E看到的鱼数增5
        for (i = 4; i >= 1; i--) {
            if (fish[i + 1] % 4 != 0)
                break; // 跳出for循环
            else
                fish[i] = fish[i + 1] * 5 / 4 + 1; // 计算第i个人看到的鱼数
        }
    } while (i >= 1); // 当i>=1时,继续做do循环
    // 输出计算结果
    for (i = 1; i <= 5; i++)
        printf("第%d个人看到的鱼是%d条。\n", i, fish[i]);
}
void solution2() {
    int n, x, j, k, l, m;
    for (n = 6;; n += 5) {
        j = 4 * (n - 1) / 5;
        if (j % 5 != 1)
            continue;
        k = 4 * (j - 1) / 5;
        if (k % 5 != 1)
            continue;
        l = 4 * (k - 1) / 5;
        if (l % 5 != 1)
            continue;
        m = 4 * (l - 1) / 5;
        if (m % 5 != 1)
            continue;
        /*        if (n % 5 == 1 && j % 5 == 1 && k % 5 == 1 && l % 5 == 1 &&*/
        /*            m % 5 == 1) {*/
        printf("至少合伙捕鱼：%d条\n", n);
        printf("分布捕鱼条数：%d %d %d %d\n", j, k, l, m);
        break;
        /*        }*/
    }
}
int main() {
    solution1();
    solution2();
}
