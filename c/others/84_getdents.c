/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : 84_getdents.c
* Author : gongchengra@gmail.com
* Purpose : http://man7.org/linux/man-pages/man2/getdents.2.html
* http://be-n.com/spw/you-can-list-a-million-files-in-a-directory-but-not-with-ls.html
* works in linux only.
* Creation Date : 2020-04-24
* Last Modified : 2020-04-24 14:23:53+0800
_._._._._._._._._._._._._._._._._._._._._.*/
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/syscall.h>
#include <unistd.h>
#define hand_error(msg)                                                        \
    do {                                                                       \
        perror(msg);                                                           \
        exit(EXIT_FAILURE);                                                    \
    } while (0)
struct linux_dirent {
    long d_ino;
    off_t d_off;
    unsigned short d_reclen;
    char d_name[];
};
#define BUFSIZE 1024
int main(int argc, char **argv) {
    int fd, nread;
    char buf[BUFSIZE];
    struct linux_dirent *d;
    int bpos;
    char d_type;
    fd = open(argc > 1 ? argv[1] : ".", O_RDONLY | O_DIRECTORY);
    if (fd == -1) {
        hand_error("open");
    }
    for (;;) {
        nread = syscall(SYS_getdents, fd, buf, BUFSIZE);
        if (nread == -1)
            hand_error("getents");
        if (nread == 0)
            break;
        printf("--------------- nread=%d ---------------\n", nread);
        printf("inode#    file type  d_reclen  d_off   d_name\n");
        for (bpos = 0; bpos < nread; bpos += d->d_reclen) {
            d = (struct linux_dirent *)(buf + bpos);
            printf("%8ld ", d->d_ino);
            d_type = *(buf + bpos + d->d_reclen - 1);
            printf("%-10s",
                   (d_type == DT_REG)
                       ? "regular"
                       : (d_type == DT_DIR)
                             ? "directory"
                             : (d_type == DT_FIFO)
                                   ? "FIFO"
                                   : (d_type == DT_SOCK)
                                         ? "socket"
                                         : (d_type == DT_LNK)
                                               ? "symlink"
                                               : (d_type == DT_BLK)
                                                     ? "block dev"
                                                     : (d_type == DT_CHR)
                                                           ? "char dev"
                                                           : "???");
            printf("%4d %10lld  %s\n", d->d_reclen, (long long)d->d_off,
                   d->d_name);
        }
    }
}
