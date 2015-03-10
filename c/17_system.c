/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : 17_system.c

* Author : gongchengra@gmail.com

* Purpose : learn how to use system() function;

* Creation Date : 2015-02-12

* Last Modified :

_._._._._._._._._._._._._._._._._._._._._.*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int main()
{
    system("ifconfig eth0");
    FILE *f = popen("ifconfig eth0", "r");
    if (f) {
            char buf[SIZE];
            while (fread(buf, SIZE, 1, f)) {
                        printf("%s", buf);
                    }
            pclose(f);
        }
    return 0;
}
