#include "student.h"
/********************
 * 输出表头
 ********************/
void showTable(void) {
    int j;
    printf("学号\t姓名\t性别");
    for (j = 0; j < NUM_SUBJECT; j++)
        printf("\t%s", subject[j]);
    printf("\t总分\t平均分\t名次\n");
}
/***********************
 * 显示所有的学生信息
 ***********************/
void display(void) {
    int i, j;
    if (numStus == 0) {
        printf("没有可供显示的记录！");
        return;
    }
    showTable();
    for (i = 0; i < numStus; i++) {
        // 打印学生信息
        printf("%s\t%s\t%s", records[i].number, records[i].name,
               records[i].gender);
        for (j = 0; j < NUM_SUBJECT; j++)
            printf("\t%.1f", records[i].score[j]);
        printf("\t%.1f\t%.1f\t%d\n", records[i].sum, records[i].average,
               records[i].index);
        // 打印满20个记录后停下来
        if (i % 19 == 0 && i != 0) {
            printf("输入任一字符后继续...\n");
            getch();
            printf("\n\n");
            showTable();
        }
    }
}
/*****************************
 * 在当前表的末尾增加新的信息
 * 结果：records中将记录新的信
 * 息，如果数组大小不够，会重
 * 新申请数组空间
 *****************************/
void addRecord(void) {
    char str[10];
    int j;
    float mark, sum;
    if (numStus == 0)
        printf("原来没有记录，现在建立新表\n");
    else
        printf("下面在当前表的末尾增加新的信息\n");
    while (1) {
        printf("您将要添加一组信息，确定吗？(Y/n)");
        gets(str);
        if (str[0] == 'n' || str[0] == 'N') // 不再添加新的信息
            break;
        if (numStus >= arraySize) // 现在的数组空间不足，需要重新申请空间
        {
            records =
                realloc(records, (arraySize + INCR_SIZE) * sizeof(StuInfo));
            if (records == NULL) {
                printf("memory failed!");
                exit(-1);
            }
            arraySize = arraySize + INCR_SIZE;
        }
        printf("请输入学号：");
        gets(records[numStus].number);
        printf("请输入姓名：");
        gets(records[numStus].name);
        printf("请输入性别（0为女，1为男）：");
        gets(str);
        if (str[0] == '0')
            strcpy(records[numStus].gender, "女");
        else
            strcpy(records[numStus].gender, "男");
        sum = 0;
        for (j = 0; j < NUM_SUBJECT; j++) {
            printf("请输入%s成绩：", subject[j]);
            gets(str);
            mark = (float)atof(str);
            records[numStus].score[j] = mark;
            sum += mark;
        }
        records[numStus].sum = sum;
        records[numStus].average = sum / NUM_SUBJECT;
        records[numStus].index = getIndex(sum);
        numStus++;
    }
    printf("现在一共有%d条信息\n", numStus);
    savedTag = 1;
}
/********************************************************
 * 找出总分为sum在第0至numStus-1个记录中按升序排序的位置
 * 参数：sum欲找出的某位置的总分
 * 返回：sum在第0至numStus-1个记录中按升序排序的位置
 * 结果：第0至numStus-1个记录中名次一项也会以需要相应改变
 ********************************************************/
int getIndex(float sum) {
    int i;
    int count = 0; // 总分大于sum的人数
    for (i = 0; i < numStus; i++) {
        if (records[i].sum < sum) {
            records[i].index++; // 总分小于sum的记录名次增1
        } else if (records[i].sum > sum) {
            count++;
        }
    }
    return count + 1;
}
