//#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>
#define BUFSIZ 100
#define EOF -1
/* getchar: unbuffered single character input */
int getcharv1(void)
{
    char c;
    return (read(0, &c, 1) == 1) ? (unsigned char) c : EOF;
}
int getcharv2(void)
{
    static char buf[BUFSIZ];
    static char *bufp = buf;
    static int n = 0;
    if (n == 0) { /* buffer is empty */
        n = read(0, buf, sizeof buf);
        bufp = buf;
    }
    return (--n >= 0) ? (unsigned char) *bufp++ : EOF;
}
int main(){
    getcharv1();
    getcharv2();
}
