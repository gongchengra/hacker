#ifndef H_STUDENT_HH
#define H_STUDENT_HH
#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INITIAL_SIZE 100 // 数组初始大小
#define INCR_SIZE 50     // 数组每次增加的大小
#define NUM_SUBJECT 5    // 科目数
struct student_info {
    char number[15];          // 学号
    char name[20];            // 姓名
    char gender[4];           // 性别
    float score[NUM_SUBJECT]; // 分别为该学生5门课的成绩
    float sum;                // 总分
    float average;            // 平均分
    int index;                // 名次
};
typedef struct student_info StuInfo;
extern int numStus;      // 记录的学生数
extern StuInfo *records; // 记录学生信息的数组
extern char savedTag; // 信息是否已保存的标志，0为已保存，1为未保存
extern int arraySize; // 数组大小
extern char *subject[];
void handle_menu(void);
int menu_select(void);
void addRecord(void);
void modifyRecord(void);
void display(void);
void queryInfo(void);
void removeRecord(void);
void sortInfo(void);
int saveRecords(void);
int loadRecords(void);
void quit(void);
void showTable(void);
int findRecord(char *target, int targetType, int from);
int getIndex(float sum);
void copyRecord(StuInfo *src, StuInfo *dest);
#endif // H_STUDENT_HH
