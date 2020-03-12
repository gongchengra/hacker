// 贪吃蛇的源码
// a—向左转 d—向右转 s—向下运动 w—向上运动
/*#include <conio.h>*/
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
typedef struct snake {
    int a;
    int b;
    struct snake *u;
    struct snake *n;
} snake, *snake1;
typedef struct food {
    int a;
    int b;
} food;
int main() {
    char c, c0 = 'd';
    int i, j, k, n = 1, t, at;
    snake p, q;
    snake *dd, *dd0, *dd1, *dd2;
    food f;
    srand(time(NULL));
    p.u = NULL;
    p.n = &q;
    p.a = 5;
    p.b = 6;
    q.a = 5;
    q.b = 5;
    q.u = &p;
    q.n = NULL;
    dd = dd2 = &q;
    f.a = (rand() % 15 + 1);
    f.b = (rand() % 15 + 1);
    while (1) {
        srand(time(NULL));
        system("clear");
        // 双重循环
        for (i = 0; i < 17; i++) // for11
        {
            for (j = 0; j < 17; j++) // for21
            {
                if (i == 0)
                    printf("▁");
                else if (i == 16)
                    printf("▔");
                else if (j == 0)
                    printf("▕");
                else if (j == 16)
                    printf("▏");
                else if (i == p.a && j == p.b)
                    printf("■");
                else if (i == f.a && j == f.b)
                    printf("★");
                else {
                    t = 0;
                    dd = dd2;
                    for (k = 0; k < n; k++) // for23
                    {
                        if (i == dd->a && j == dd->b) {
                            printf("□");
                            t = 1;
                            break;
                        }
                        dd = dd->u;
                    } // endfor23
                    if (t == 0)
                        printf(" ");
                } // endelse
            }     // endfor21
            printf("\n");
        } // endfor11
        // 结束双重循环
        at = 0;
        dd = dd2;
        for (i = 0; i < n; i++) // for
        {
            if (p.a == dd->a && p.b == dd->b) {
                printf("game over!!\n");
                exit(0);
            }
            dd = dd->u;
        }                             // endfor
        if (p.a == f.a && p.b == f.b) // if
        {
            dd = dd2;
            at = 1;
            f.a = (rand() % 15 + 1);
            f.b = (rand() % 15 + 1);
            for (i = 0; i < n; i++) // for
            {
                if (f.a == dd->a && f.b == dd->b) {
                    f.a = dd2->a;
                    f.b = dd2->b;
                    break;
                }
            } // endfor
            n++;
        } // endif
        // 处理按键if语句
        if (kbhit()) // if11
        {
            c = getch();
            dd = dd2;
            if (c == 'w' && c0 != 's') // if21
            {
                if (at == 1) // if31
                {
                    dd0 = (snake1)malloc(sizeof(snake));
                    dd0->a = dd2->a;
                    dd0->b = dd2->b;
                    dd0->n = NULL;
                    dd0->u = dd2;
                    dd2 = dd0;
                } // endif31
                dd = dd2;
                for (i = 0; i < n; i++) {
                    dd1 = dd->u;
                    dd->b = dd1->b;
                    dd->a = dd1->a;
                    dd = dd->u;
                }
                if (p.a == 1)
                    p.a = 15;
                else
                    p.a = (p.a - 1) % 15;
            }                               // endif21
            else if (c == 's' && c0 != 'w') // if22
            {
                if (at == 1) {
                    dd0 = (snake1)malloc(sizeof(snake));
                    dd0->a = dd2->a;
                    dd0->b = dd2->b;
                    dd0->n = NULL;
                    dd0->u = dd2;
                    dd2 = dd0;
                }
                dd = dd2;
                for (i = 0; i < n; i++) {
                    dd1 = dd->u;
                    dd->b = dd1->b;
                    dd->a = dd1->a;
                    dd = dd->u;
                }
                p.a = (p.a % 15) + 1;
            }                               // endif22
            else if (c == 'a' && c0 != 'd') // if23
            {
                if (at == 1) {
                    dd0 = (snake1)malloc(sizeof(snake));
                    dd0->a = dd2->a;
                    dd0->b = dd2->b;
                    dd0->n = NULL;
                    dd0->u = dd2;
                    dd2 = dd0;
                }
                dd = dd2;
                for (i = 0; i < n; i++) {
                    dd1 = dd->u;
                    dd->b = dd1->b;
                    dd->a = dd1->a;
                    dd = dd->u;
                }
                if (p.b == 1)
                    p.b = 15;
                else
                    p.b = (p.b - 1) % 15;
            }                               // endif23
            else if (c == 'd' && c0 != 'a') // if24
            {
                if (at == 1) {
                    dd0 = (snake1)malloc(sizeof(snake));
                    dd0->a = dd2->a;
                    dd0->b = dd2->b;
                    dd0->n = NULL;
                    dd0->u = dd2;
                    dd2 = dd0;
                }
                dd = dd2;
                for (i = 0; i < n; i++) {
                    dd1 = dd->u;
                    dd->b = dd1->b;
                    dd->a = dd1->a;
                    dd = dd->u;
                }
                p.b = (p.b % 15) + 1;
            }    // endif24
            else // if25
            {
                goto qq;
            } // endif25
            c0 = c;
        } else // ifgoto
        {
        qq:
            if (c0 == 'w') {
                if (at == 1) {
                    dd0 = (snake1)malloc(sizeof(snake));
                    dd0->a = dd2->a;
                    dd0->b = dd2->b;
                    dd0->n = NULL;
                    dd0->u = dd2;
                    dd2 = dd0;
                }
                dd = dd2;
                for (i = 0; i < n; i++) {
                    dd1 = dd->u;
                    dd->b = dd1->b;
                    dd->a = dd1->a;
                    dd = dd->u;
                }
                if (p.a == 1)
                    p.a = 15;
                else
                    p.a = (p.a - 1) % 15;
            }                   // endif11
            else if (c0 == 's') // if12
            {
                if (at == 1) {
                    dd0 = (snake1)malloc(sizeof(snake));
                    dd0->a = dd2->a;
                    dd0->b = dd2->b;
                    dd0->n = NULL;
                    dd0->u = dd2;
                    dd2 = dd0;
                }
                dd = dd2;
                for (i = 0; i < n; i++) {
                    dd1 = dd->u;
                    dd->b = dd1->b;
                    dd->a = dd1->a;
                    dd = dd->u;
                }
                p.a = (p.a % 15) + 1;
            }                   // endif12
            else if (c0 == 'a') // f13
            {
                if (at == 1) {
                    dd0 = (snake1)malloc(sizeof(snake));
                    dd0->a = dd2->a;
                    dd0->b = dd2->b;
                    dd0->n = NULL;
                    dd0->u = dd2;
                    dd2 = dd0;
                }
                dd = dd2;
                for (i = 0; i < n; i++) {
                    dd1 = dd->u;
                    dd->b = dd1->b;
                    dd->a = dd1->a;
                    dd = dd->u;
                }
                if (p.b == 1)
                    p.b = 15;
                else
                    p.b = (p.b - 1) % 15;
            }                   // endif13
            else if (c0 == 'd') // if14
            {
                if (at == 1) {
                    dd0 = (snake1)malloc(sizeof(snake));
                    dd0->a = dd2->a;
                    dd0->b = dd2->b;
                    dd0->n = NULL;
                    dd0->u = dd2;
                    dd2 = dd0;
                }
                dd = dd2;
                for (i = 0; i < n; i++) {
                    dd1 = dd->u;
                    dd->b = dd1->b;
                    dd->a = dd1->a;
                    dd = dd->u;
                }
                p.b = (p.b % 15) + 1;
            } // endif14
        }     // endif11
        fflush(stdin);
        dd = &q;
        sleep(200);
    } // endwhile
}
