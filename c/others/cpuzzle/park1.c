#include "park.h"
void InitStack(Stack *s) // 初始化栈
{
    s->point = -1;
}
Queue *InitQueue() // 初始化队列
{
    Queue *q;
    q = (Queue *)malloc(sizeof(Queue));
    q->next = NULL;
    return q;
}
int StackPop(Stack *s, long *i, int *j) // 退栈函数
{
    if (s->point == -1)
        return false;
    else {
        *i = s->pos[s->point];
        *j = s->time[s->point];
        s->point--;
        return true;
    }
}
int StackPush(Stack *s, long i, int j) // 压栈函数
{
    if (s->point == MAX_PARKING_SIZE - 1)
        return false;
    else {
        s->point++;
        s->pos[s->point] = i;
        s->time[s->point] = j;
        return true;
    }
}
int QueuePop(Queue **qH, long *i) // 退队函数
{
    Queue *temp;
    if ((*qH)->next == NULL)
        return false;
    else {
        temp = (*qH)->next;
        (*qH)->next = temp->next;
        *i = temp->num;
        free(temp);
        return true;
    }
}
int QueuePush(Queue **q, long i) // 入队函数
{
    Queue *temp;
    if ((temp = (Queue *)malloc(sizeof(Queue))) == NULL)
        return false;
    else {
        (*q)->next = temp;
        temp->num = i;
        temp->next = NULL;
        *q = temp;
        return true;
    }
}
