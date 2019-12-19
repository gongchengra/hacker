/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : ex5.c

* Author : gongchengra@gmail.com

* Purpose :

* Creation Date : 2015-02-03

* Last Modified :

_._._._._._._._._._._._._._._._._._._._._.*/

#include <stdio.h>
int main(int argc, char *argv[])
{
    int distance = 100;
    int i;
    printf("There are %d arguments for this program.\n", argc);
    for(i=0;i<argc;i++){
        printf("%s\n", argv[i]);
    }
    printf("You are %d miles away.\n", distance);
    return 0;
}
