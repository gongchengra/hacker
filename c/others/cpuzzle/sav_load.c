#include "student.h"
/**********************************
 * 文件存储操作函数
 * 结果：数组records被保存至指定文件
 * 返回：成功0，失败-1
 **********************************/
int saveRecords() {
    FILE *fp;
    char fname[30];
    if (numStus == 0) {
        printf("没有记录可存！");
        return -1;
    }
    printf("请输入要存入的文件名（直接回车选择文件stu_info）：");
    gets(fname);
    if (strlen(fname) == 0)
        strcpy(fname, "stu_info");
    if ((fp = fopen(fname, "wb")) == NULL) {
        printf("不能存入文件！\n");
        return -1;
    }
    printf("\n存文件...\n");
    fwrite(records, sizeof(StuInfo) * numStus, 1, fp);
    fclose(fp);
    printf("%d条记录已经存入文件，请继续操作。\n", numStus);
    savedTag = 0; // 更新是否已保存的标记
    return 0;
}
/*******************************************
 * 文件读取操作函数
 * 结果：records将为从指定文件中读取出的记录
 * 返回：成功0，失败-1
 *******************************************/
int loadRecords(void) {
    FILE *fp;
    char fname[30];
    char str[5];
    if (numStus != 0 && savedTag == 0) {
        printf("请选择您是要覆盖现有记录(Y)，还是要将");
        printf("读取的记录添加到现有记录之后(n)？\n");
        printf("直接回车则覆盖现有记录\n");
        gets(str);
        if (str[0] == 'n' || str[0] == 'N') { // 将读取的记录添加到现有记录之后
            savedTag = 1;
        } else {
            if (savedTag == 1) { // 覆盖现有记录
                printf("读取文件将会更改原来的记录，");
                printf("是否保存原来的记录？(Y/n)");
                gets(str);
                if (str[0] != 'n' && str[0] != 'N')
                    saveRecords();
            }
            numStus = 0;
        }
    }
    printf("请输入要读取的文件名（直接回车选择文件stu_info）：");
    gets(fname);
    if (strlen(fname) == 0)
        strcpy(fname, "stu_info");
    if ((fp = fopen(fname, "rb")) == NULL) {
        printf("打不开文件！请重新选择\n");
        return -1;
    }
    printf("\n取文件...\n");
    while (!feof(fp)) {
        // 现在的数组空间不足，需要重新申请空间
        if (numStus >= arraySize) {
            records =
                realloc(records, (arraySize + INCR_SIZE) * sizeof(StuInfo));
            if (records == NULL) {
                printf("memory failed!");
                exit(-1);
            }
            arraySize = arraySize + INCR_SIZE;
        }
        if (fread(&records[numStus], sizeof(StuInfo), 1, fp) != 1)
            break;
        // 按照addRecord函数的方法，更新名次
        records[numStus].index = getIndex(records[numStus].sum);
        numStus++;
    }
    fclose(fp);
    printf("现在共有%d条记录。", numStus);
    return 0;
}
