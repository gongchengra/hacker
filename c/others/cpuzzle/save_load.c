#include "record.h"
// 文件存储操作函数
void save(const ADDR *top) {
    const ADDR *p;
    FILE *fp;
    if (count == 0) {
        printf("没有记录可存！");
        return;
    }
    if ((fp = fopen("sname", "wb")) == NULL) {
        printf("不能打开文件！\n");
        exit(1);
    }
    printf("\n存文件\n");
    p = top;
    while (p) {
        fwrite(p, LEN, 1, fp);
        p = p->next;
    }
    fclose(fp);
    printf("%d条记录已经存入文件，请继续操作。\n", count);
}
// 文件读取操作函数
ADDR *load(ADDR *top) {
    FILE *fp;
    ADDR *p, *old;
    count = 0;
    if ((fp = fopen("sname", "rb")) == NULL) {
        printf("打不开文件！\n");
        exit(1);
    }
    printf("\n取文件...\n");
    ASK(p);
    top = p;
    old = top;
    while (!feof(fp)) {
        if (1 != fread(p, LEN, 1, fp))
            break;
        count = count + 1;
        ASK(p->next);
        old = p->next;
        old = p;
        p = p->next;
    }
    old->next = NULL;
    fclose(fp);
    printf("取入%d条记录。", count);
    return (top);
}
