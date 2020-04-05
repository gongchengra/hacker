/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : test.c
* Author : gongchengra@gmail.com
* Purpose :
* Creation Date : 2014-12-02
* Last Modified :
_._._._._._._._._._._._._._._._._._._._._.*/
struct foo;
typedef struct foo FILE;
extern int fputs(const char *, FILE *);
extern FILE *stdout;
int main(void)
{
    fputs("Hello, world!\n", stdout);
    return 0;
}
