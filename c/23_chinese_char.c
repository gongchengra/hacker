/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : 23_chinese_char.c

* Author : gongchengra@gmail.com

* Purpose :

* Creation Date : 2016-12-27

* Last Modified :

_._._._._._._._._._._._._._._._._._._._._.*/

#include <stdio.h>
/*#include <locale.h>*/
/*#include <wchar.h>*/
int main(void) {
/*    setlocale(LC_CTYPE, "");*/
    char str[] = "中文";
/*    wchar_t wstr[] = L"中文";*/
    printf("1:%s\n", str);
/*    wprintf(L"2:%s\n", wstr);*/
    return 0;
}
