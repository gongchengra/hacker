#include "record.h"
ADDR *delete_record(ADDR *top) {
    char choose[2], input[30];
    int cn = 0;
    int flage;
    ADDR *old, *star;
    for (;;) {
        flage = 1;
        if (count == 0) {
            printf("记录已经为空表，退出删除操作！");
            return top;
        }
        printf("1. 通过代号\n");
        printf("2. 通过号码\n");
        printf("3. 退出操作\n");
        printf("选择1-3:");
        gets(choose);
        while (1) {
            cn = atoi(choose);
            if (cn < 1 || cn > 3) {
                printf("输入错误，重选1-3：");
                gets(choose);
            } else
                break;
        }
        switch (cn) {
        case 1:
            printf("请输入代号：");
            break;
        case 2:
            printf("请输入号码：");
            break;
        case 3:
            printf("退出删除操作\n");
            return top;
        }
        gets(input);
        old = star = top;
        while (star != NULL) {
            if ((cn == 1 && strcmp(input, star->name) == 0) ||
                (cn == 2 && strcmp(input, star->tel) == 0)) {
                if (star == top) {
                    top = star->next;
                } else {
                    old->next = star->next;
                }
                free(star);
                --count;                    // 调整计数器
                printf("已经删除该记录\n"); // 给出删除成功的信息
                flage = 0;
                break;
            } else {
                old = star;
                star = star->next;
            }
        }
        if (flage != 0) {
            printf("没有找到该记录\n");
            flage = 1;
        }
        continue;
    }
}
