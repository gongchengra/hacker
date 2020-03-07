#include <stdio.h>
#include <stdlib.h>
int main() {
    int i, sum = 0, min = 100, *p;
    char **pcm;
    char(*pcn)[7];
    int a[8] = {75, 80, 83, 85, 86, 30};
    char *MeanLow[4] = {"人数", "平均成绩", "最低分数科目的成绩",
                        "最低分数的科目"};
    char name[5][7] = {"数学", "物理", "外语", "政治", "体育"};
    for (i = 0; i < 5; i++)
        printf("%s:%d\n", name[i], a[i]);
    for (i = 0; i < 3; i++)
        printf("%s:%d\n", MeanLow[i], a[i + 5]);
    printf("%s:\n", MeanLow[i]);
    // 计算
    p = a;
    for (i = 0; i < 5; i++) {
        sum = sum + p[i];
        if (min > p[i])
            min = p[i];
    }
    p[6] = sum / 5;
    p[7] = min;
    pcm = MeanLow;
    pcn = name;
    // 输出信息
    printf("\n全班各科平均成绩如下：\n");
    for (i = 0; i < 5; i++)
        printf("%s:%d\n", pcn[i], *(p + i));
    printf("\n统计结果如下：\n");
    for (i = 0; i < 3; i++)
        printf("%s:%d\n", pcm[i], *(p + i + 5));
    return 0;
}
