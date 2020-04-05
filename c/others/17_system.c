/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : 17_system.c
* Author : gongchengra@gmail.com
* Purpose : learn how to use system() function;
* Creation Date : 2015-02-12
* Last Modified :
_._._._._._._._._._._._._._._._._._._._._.*/
#include <stdio.h>
#include <stdlib.h>
#define SIZE 1000
int main() {
    system("ifconfig");
#if 0
    FILE *f = popen("ifconfig", "r");
    if (f) {
        char buf[SIZE];
        while (fread(buf, SIZE, 1, f)) {
            printf("%s", buf);
        }
        pclose(f);
    }
#endif
    return 0;
}
