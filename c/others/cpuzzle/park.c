#include "park.h"
int main() {
    int time, i, j, inStack, inQueue;
    long num;
    char state;
    Stack park;
    Queue *H, *p, *temp, *temp2;
    H = InitQueue();
    p = H;
    InitStack(&park); // 初始化队列和栈
    printf("**********这里是停车场管理程序,欢迎使用**************\n");
    printf("\n停车场最大能停车%d辆,停车时间不得超过24小时,现在停车的单价为 "
           "每小时%.2f元\n",
           MAX_PARKING_SIZE, PRIZE);
    while (1) {
        inStack = inQueue = 0;
        temp = H;
        printf("******************************\n");
        printf("         停车场管理系统\n");
        printf("(A或a)汽车到达和已到汽车查询\n");
        printf("(D或d)汽车离开\n");
        printf("(E或e)程序退出\n");
        printf("******************************\n");
        printf("\n您的选择是:");
        while((state = getchar())=='\n');
        if (state == 'a' || state == 'A' || state == 'd' || state == 'D') {
            printf("\n输入车牌号(数字):");
            scanf("%ld", &num);
            printf("\n输入到达或查询或离开的时间(24小时制,单位:小时):");
            scanf("%d", &time);
        }
        if (state == 'a' || state == 'A') {
            for (i = 0; i <= park.point; i++)
                if (park.pos[i] == num) {
                    inStack = 1;
                    break;
                } // 在车站中查找
            for (j = 1; temp->next != NULL; j++) {
                temp2 = temp;
                temp = temp2->next;
                if (temp->num == num) {
                    inQueue = 1;
                    break;
                }
            } // 在车站外查找
            if (inStack)
                printf("\n查询结果:输入的汽车已经在车站中第%d个位置停留了%"
                       "d个小时 !\n ",
                       i + 1,
                       time > park.time[i] ? time - park.time[i]
                                           : time + 24 - park.time[i]);
            else if (inQueue)
                printf("\n查询结果:输入的汽车已经在车站外第%d个位置等候\n", j);
            else {
                if (StackPush(&park, num, time) == false) {
                    QueuePush(&p, num);
                    printf("\n车站已满,车辆停在场外。\n");
                } else
                    printf("\n车辆成功进站!\n");
            } // 车辆到达时，若车站已满，则停在车站外，否则进入车站
        } else if (state == 'd' || state == 'D') // 如果是离开
        {
            for (i = 0; i <= park.point; i++)
                if (park.pos[i] == num) {
                    inStack = 1;
                    break;
                }        // 在车站中查找
            if (inStack) // 如果在车站中
            {
                printf("正要离开的汽车在车站中第%d个位置停留了%d个小时,应付%."
                       "2f元\n ",
                       i + 1,
                       time > park.time[i] ? time - park.time[i]
                                           : time + 24 - park.time[i],
                       time > park.time[i]
                           ? (time - park.time[i]) * PRIZE
                           : (time + 24 - park.time[i]) * PRIZE);
                while (i < park.point) {
                    park.pos[i] = park.pos[i + 1];
                    park.time[i] = park.time[i + 1];
                    i++;
                }
                park.point--; // 把离开的车辆从车站中删除
                if (H->next != NULL) {
                    QueuePop(&H, &num);
                    if (H->next == NULL)
                        p = H;
                    StackPush(&park, num, time);
                    printf("\n停车场空出一位置。场外等候的%ld号汽车入站了!\n",
                           num);
                }  // 如果车站外有车，入站
            } else // 不在车站中
            {
                for (i = 1; temp->next != NULL; i++) {
                    temp2 = temp;
                    temp = temp2->next;
                    if (temp->num == num) {
                        inQueue = 1;
                        break;
                    }
                } // 查找是否在车站外
                if (inQueue) {
                    printf("\n汽车在停车场外,不收费\n");
                    temp2->next = temp->next;
                    if (temp == p)
                        p = temp2;
                    free(temp);
                } // 在车站外
                else
                    printf("\n对不起，您输入了不存在的车牌号!\n");
            }
        } else if (state == 'e' || state == 'E') {
            printf("\n");
            break;
        } else
            printf("\n输入错误!\n");
    }
    return 0;
}
