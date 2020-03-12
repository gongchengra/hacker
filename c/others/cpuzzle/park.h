#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>
#include <curses.h>
#define MAX_PARKING_SIZE 10 // 停车场最大停车数量
#define PRIZE 5.00          // 停留每小时单价
#define true 1
#define false 0
typedef struct stack {
    long pos[MAX_PARKING_SIZE]; // 存储车牌号码
    int time[MAX_PARKING_SIZE]; // 存储进入时间
    int point;                  // 最后一辆车的位置指针
} Stack;                        // 定义栈-模拟停车场
typedef struct queue {
    int num;                             // 存储车牌号
    struct queue *next;                  // 指向下一辆车
} Queue;                                 // 定义队列-模拟停车场外
void InitStack(Stack *s);                // 初始化栈
Queue *InitQueue();                      // 初始化队列
int StackPop(Stack *s, long *i, int *j); // 退栈函数
int StackPush(Stack *s, long i, int j);  // 压栈函数
int QueuePop(Queue **qH, long *i);       // 退队函数
int QueuePush(Queue **q, long i);        // 入队函数
