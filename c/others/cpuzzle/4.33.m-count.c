#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[]) {
    int N = (argc > 2) ? atoi(argv[1]) : 5;
    char num[N][14];
    int i = 0, m = 0, j = 0, k = 0;
    int length = 0;
    char s[14];
    if (argc > 2)
        m = atoi(argv[2]);
    else {
        printf("请输入间隔数:");
        scanf("%d", &m); // 初始报数值
        printf("请准备输入游戏者名字\n");
        getchar();
    }
    // 输入参加游戏人的名字
    for (i = 0; i < N; i++) {
        printf("第%d个人的名字:", i + 1);
        // gets(s);
        fgets(s, 14, stdin);
        strcpy(num[i], s);
    }
    printf("出圈的顺序如下:\n");
    i = -1; // 调整计数器
    for (k = 1; k <= N; k++) {
        j = 0;
        while (j < m) {
            i++;
            if (i == N) // 返回到第一个位置
                i = 0;
            if (num[i][0] != '0')
                j++; // 若该人员在圈中，则计数有效
        }
        printf("%s ", num[i]); // 输出出圈人的信息
        num[i][0] = '0';       // 标识该人员已出圈
    }
    printf("\n");
}
