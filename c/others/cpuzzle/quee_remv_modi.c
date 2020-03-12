#include "student.h"
/**************************************************************
 * 查找指定的记录
 * 参数： target:欲查找记录的某一项与target相同
 * targetType:表明通过哪一项来查找，0为学号，1为姓名，2为名次
 * from:从第from个记录开始找
 * 返回：找到的记录的序号，若找不到则返回-1
 **************************************************************/
int findRecord(char *target, int targetType, int from) {
    int i;
    for (i = from; i < numStus; i++) {
        if ((targetType == 0 && strcmp(target, records[i].number) == 0) ||
            (targetType == 1 && strcmp(target, records[i].name) == 0) ||
            (targetType == 2 && atoi(target) == records[i].index))
            return i;
    }
    return -1;
}
/********************************
 * 查询指定学生的信息
 * 可以按照学号、姓名或名次来查询
 ********************************/
void queryInfo(void) {
    char str[5];
    char target[20];
    int type;
    int count;
    int i, j;
    if (numStus == 0) {
        printf("没有可供查询的记录");
        return;
    }
    while (1) {
        printf("请输入查询的方式：（直接输入回车则结束查询）\n");
        printf("1. 按学号\n");
        printf("2. 按姓名\n");
        printf("3. 按名次\n");
        gets(str);
        if (strlen(str) == 0)
            break;
        if (str[0] == '1') {
            printf("请输入欲查询的学生的学号：");
            gets(target);
            type = 0;
        } else if (str[0] == '2') {
            printf("请输入欲查询的学生的姓名：");
            gets(target);
            type = 1;
        } else {
            printf("请输入欲查询的学生的名次：");
            gets(target);
            type = 2;
        }
        i = findRecord(target, type, 0);
        if (i == 1) {
            // 打印查询到的学生的信息
            showTable();
        }
        count = 0;
        while (i != -1) {
            count++;
            printf("%s\t%s\t%s", records[i].number, records[i].name,
                   records[i].gender);
            for (j = 0; j < NUM_SUBJECT; j++)
                printf("\t%.1f", records[i].score[j]);
            printf("\t%.1f\t%.1f\t%d\n", records[i].sum, records[i].average,
                   records[i].index);
            i = findRecord(target, type, i + 1);
        }
        if (count == 0)
            printf("没有符合条件的学生！\n");
        else
            printf("一共找到了%d名学生的信息\n\n", count);
    }
}
/************************
 * 删除指定的记录
 ************************/
void removeRecord(void) {
    char str[5];
    char target[20];
    int type;
    int i, j;
    int tmpi;
    if (numStus == 0) {
        printf("没有可供删除的记录");
        return;
    }
    while (1) {
        printf("请输入如何找å°欲删除的记录的方式：");
        printf("（直接输入回车则结束移除操作）\n");
        printf("1. 按学号\n");
        printf("2. 按姓名\n");
        printf("3. 按名次\n");
        gets(str);
        if (strlen(str) == 0)
            break;
        if (str[0] == '1') {
            printf("请输入该学生的学号：");
            gets(target);
            type = 0;
        } else if (str[0] == '2') {
            printf("请输入该学生的姓名：");
            gets(target);
            type = 1;
        } else {
            printf("请输入该学生的名次：");
            gets(target);
            type = 2;
        }
        i = findRecord(target, type, 0);
        if (i == -1)
            printf("没有符合条件的学生！\n");
        while (i != -1) {
            showTable();
            printf("%s\t%s\t%s", records[i].number, records[i].name,
                   records[i].gender);
            for (j = 0; j < NUM_SUBJECT; j++)
                printf("\t%.1f", records[i].score[j]);
            printf("\t%.1f\t%.1f\t%d\n", records[i].sum, records[i].average,
                   records[i].index);
            printf("确定要删除这个学生的信息吗？(y/N)");
            gets(str);
            if (str[0] == 'y' || str[0] == 'Y') {
                numStus--;
                tmpi = records[i].index;
                // 将后面的记录前移
                for (j = i; j < numStus; j++) {
                    copyRecord(&records[j + 1], &records[j]);
                }
                // 将名次排在被删除记录后面的记录的名次减1
                for (j = 0; j < numStus; j++) {
                    if (records[j].index > tmpi)
                        records[j].index--;
                }
            }
            // 取下一个符合条件的记录
            i = findRecord(target, type, i + 1);
        }
    }
    savedTag = 1;
}
/*****************************************
 * 将src指向的一条记录复制给dest指向的记录
 *****************************************/
void copyRecord(StuInfo *src, StuInfo *dest) {
    int j;
    strcpy(dest->number, src->number);
    strcpy(dest->name, src->name);
    strcpy(dest->gender, src->gender);
    for (j = 0; j < NUM_SUBJECT; j++) {
        dest->score[j] = src->score[j];
    }
    dest->sum = src->sum;
    dest->average = src->average;
    dest->index = src->index;
}
/*************************
 * 修改指定学生的信息
 *************************/
void modifyRecord(void) {
    char str[5];
    char target[20];
    int type;
    int i, j;
    int tmpi;
    float sum, mark;
    int count = 0; // 总分大于sum的人数
    if (numStus == 0) {
        printf("没有可供修改的记录");
        return;
    }
    while (1) {
        printf("请输入如何找到欲修改的记录的方式：");
        printf("（直接输入回车则结束移除操作）\n");
        printf("1. 按学号\n");
        printf("2. 按姓名\n");
        printf("3. 按名次\n");
        gets(str);
        if (strlen(str) == 0)
            break;
        if (str[0] == '1') {
            printf("请输入该学生的学号：");
            gets(target);
            type = 0;
        } else if (str[0] == '2') {
            printf("请输入该学生的姓名：");
            gets(target);
            type = 1;
        } else {
            printf("请输入该学生的名次：");
            gets(target);
            type = 2;
        }
        i = findRecord(target, type, 0);
        if (i == -1)
            printf("没有符合条件的学生！\n");
        while (i != -1) {
            showTable();
            printf("%s\t%s\t%s", records[i].number, records[i].name,
                   records[i].gender);
            for (j = 0; j < NUM_SUBJECT; j++)
                printf("\t%.1f", records[i].score[j]);
            printf("\t%.1f\t%.1f\t%d\n", records[i].sum, records[i].average,
                   records[i].index);
            printf("确定要修改这个学生的信息吗？(y/N)");
            gets(str);
            if (str[0] == 'y' || str[0] == 'Y') {
                tmpi = records[i].index;
                printf("下面请重新输入该学生的信息：\n");
                printf("请输入学号：");
                gets(records[i].number);
                printf("请输入姓名：");
                gets(records[i].name);
                printf("请输入性别（0为女，1为男）：");
                gets(str);
                if (str[0] == '0')
                    strcpy(records[i].gender, "女");
                else
                    strcpy(records[i].gender, "男");
                sum = 0;
                for (j = 0; j < NUM_SUBJECT; j++) {
                    printf("请输入%s成绩：", subject[j]);
                    gets(str);
                    mark = (float)atof(str);
                    records[i].score[j] = mark;
                    sum += mark;
                }
                records[i].sum = sum;
                records[i].average = sum / NUM_SUBJECT;
                // 将原来名次排在被修改记录之后，而其sum小于等于
                // 修改后记录的sum的记录的名次减1
                // 将原来名次排在被修改记录之前或相同，而其sum
                // 大于修改后记录的sum的记录的名次增1
                count = 0;
                for (j = 0; j < numStus; j++) {
                    if (j == i)
                        continue;
                    if (records[j].index > tmpi && records[j].sum > sum)
                        records[j].index--;
                    else if (records[j].index <= tmpi && records[j].sum < sum)
                        records[j].index++;
                    if (records[j].sum > sum)
                        count++;
                }
                records[i].index = count + 1;
            }
            // 可能有重名的学生，继续查找
            i = findRecord(target, type, i + 1);
        }
    }
    savedTag = 1;
}
