#include <stdio.h>
#include <string.h>
int main() {
    int i, sum = 0, min = 100;
    int a[8] = {75, 80, 83, 85, 86, 30};
    char *MeanLow[4] = {"人数", "平均成绩", "最低分数科目的成绩",
                        "最低分数的科目"};
    char name[6][8] = {"数学", "物理", "外语", "政治", "体育"};
    printf("原始信息如下：\n");
    for (i = 0; i < 5; i++)
        printf("%s:%d\n", name[i], a[i]);
    for (i = 0; i < 3; i++)
        printf("%s:%d\n", MeanLow[i], a[i + 5]);
    printf("%s:\n", MeanLow[i]);
    // 计算
    for (i = 0; i < 5; i++) {
        sum = sum + a[i];
        if (min > a[i])
            min = a[i];
    }
    a[6] = sum / 5;
    a[7] = min;
    /*    printf("sum = %d\n", a[6]);*/
    /*    printf("min = %d\n", a[7]);*/
    for (i = 0; i < 5; i++)
        if (min == a[i]) {
            strlcpy(name[5], name[i], sizeof(name[i]));
            break;
        }
    printf("\n全班各科平均成绩如下：\n");
    for (i = 0; i < 5; i++)
        printf("%s:%d\n", name[i], a[i]);
    printf("\n统计结果如下：\n");
    for (i = 0; i < 3; i++)
        printf("%s:%d\n", MeanLow[i], a[i + 5]);
    printf("%s:%s\n", MeanLow[3], name[5]);
}
