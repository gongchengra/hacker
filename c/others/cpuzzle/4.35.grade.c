#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    int i, *p, min = 100, sum = 0;
    int a[8] = {75, 80, 83, 85, 86, 30};
    char *pcn[6], *pcm[4];
    // 为科目名称申请内存
    for (i = 0; i < 6; i++) {
        pcn[i] = (char *)malloc(4 * sizeof(char));
        if (pcn[i] == NULL) {
            printf("内存分配错误");
            exit(1);
        }
    }
    // 为科目赋值
    strcpy(pcn[0], "数学");
    strcpy(pcn[1], "物理");
    strcpy(pcn[2], "外语");
    strcpy(pcn[3], "政治");
    strcpy(pcn[4], "体育");
    // 为人数、平均成绩、最低分数科目的成绩、最低分数的科目申请内存
    for (i = 0; i < 4; i++) {
        pcm[i] = (char *)malloc(20);
        if (pcm[i] == NULL) {
            printf("内存分配错误");
            exit(1);
        }
    }
    // 为人数等赋值
    strcpy(pcm[0], "人数");
    strcpy(pcm[1], "平均成绩");
    strcpy(pcm[2], "最低分数科目的成绩");
    strcpy(pcm[3], "最低分数的科目");
    // 为分数分配内存地址
    p = (int *)malloc(8 * sizeof(int));
    if (p == NULL) {
        printf("内存分配错误");
        exit(1);
    }
    // 存储初始值
    p[0] = 75;
    p[1] = 80;
    p[2] = 83;
    p[3] = 85;
    p[4] = 86;
    p[5] = 30;
    p[6] = 0;
    p[7] = 0;
    // 输出原始信息
    printf("原始信息如下：\n");
    for (i = 0; i < 5; i++)
        printf("%s:%d\n", pcn[i], *(p + i));
    for (i = 0; i < 3; i++) {
        printf("%s:%d\n", pcm[i], p[i + 5]);
    }
    printf("%s", pcm[3]);
    printf("\n");
    // 计算最小值和平均值
    for (i = 0; i < 5; i++) {
        sum = sum + p[i];
        if (min > p[i])
            min = p[i];
    }
    p[6] = sum / 5;
    p[7] = min;
    // 填写最低分数的科目名称
    for (i = 0; i < 5; i++)
        if (min == *(p + i)) {
            strcpy(pcn[5], pcn[i]);
            break;
        }
    printf("\n全班各科平均成绩如下:\n");
    for (i = 0; i < 5; i++)
        printf("%s:%d\n", pcn[i], p[i]);
    printf("\n统计结果如下：\n");
    for (i = 0; i < 3; i++) {
        printf("%s:%d\n", pcm[i], *(p + i + 5));
    }
    printf("%s:%s\n", pcm[3], pcn[5]);
    free(p);
    return 0;
}
