#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    char *buf;
    /*    http://www.unknownroad.com/rtfm/gdbtut/gdbsegfault.html*/
    /*    buf too large would cause segmentation fault*/
    /*    buf = malloc(1<<30);*/
    buf = malloc(1<<10);
    fgets(buf, 1024, stdin);
    printf("%s\n",buf);
    return 0;
}
