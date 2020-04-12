/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : 70_print_source_code.c
* Author : gongchengra@gmail.com
* Purpose :
* Creation Date : 2020-04-07
* Last Modified :
_._._._._._._._._._._._._._._._._._._._._.*/
#include <stdio.h>
int main(){
    FILE *fp;
    fp = fopen(__FILE__, "r");
    char c;
    do{
        c=getc(fp);
        putchar(c);
    }while(c != EOF);
    fclose(fp);
    return 0;
}
