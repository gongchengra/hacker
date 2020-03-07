#include <stdio.h>
#include <stdlib.h>
struct wkrs {
    char num[6];
    char name[10];
    int score[3];
} wk[3];
int main() {
    int i = 0, j = 0;
    char *c[4] = {"序号", "姓名", "数学", "语文"};
    printf("准备输入信息\n");
    for (i = 0; i < 3; i++) {
        printf("序号：");
        scanf("%s", wk[i].num);
        printf("姓名：");
        scanf("%s", wk[i].name);
        printf("成绩：");
        {
            for (j = 0; j < 2; j++)
                scanf("%d", &wk[i].score[j]);
        }
    }
    printf("\n%s\t%s\t%s\t%s\n", c[0], c[1], c[2], c[3]);
    for (i = 0; i < 3; i++)
        printf("%s\t%s\t%d\t%d\n", wk[i].num, wk[i].name, wk[i].score[0],
               wk[i].score[1]);
}
