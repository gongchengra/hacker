/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
 * File Name : 19_guess_num.c
 * Author : gongchengra@gmail.com
 * Purpose :
 * Creation Date : 2015-12-02
 * Last Modified :
 _._._._._._._._._._._._._._._._._._._._._.*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    srand((unsigned int)time(NULL));
    int a = rand()%9 + 1;
    int b = rand()%9 + 1;
    int num;
/*    printf("%d %d\n", a, b);*/
    int i = 0;
    int guess, guessa, guessb;
    for(i=0;;i++){
        if(i%3 == 0){
            num = a + b;
            printf("sum:");
        }else if (i%3 == 1){
            num = a - b;
            printf("differenc:");
        }else{
            num = a * b;
            printf("product:");
        }
        scanf("%d",&guess);
        if(guess>num)
        {
            printf("Too Big\n");
        }
        else if(guess<num)
        {
            printf("Too Small\n");
        }
        else
        {
            printf("Right!\n");
            scanf("%d,%d", &guessa, &guessb);
            if(guessa == a && guessb == b){
                printf("Wonderful, you got both a and b.\n");
                break;
            }else{
                printf("Try again.\n");
            }
        }
    }
    return 0;
}
