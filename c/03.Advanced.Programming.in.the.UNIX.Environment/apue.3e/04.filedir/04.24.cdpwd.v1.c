/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : 04.24.cdpwd.v1.c
* Author : gongchengra@gmail.com
* Purpose :
* Creation Date : 2020-05-07
* Last Modified : 2020-05-07 15:39:13+0800
_._._._._._._._._._._._._._._._._._._._._.*/
#include <dirent.h>
#include <errno.h> /* for definition of errno */
#include <fcntl.h> //access
#include <limits.h>
#include <stdarg.h> /* ISO C variable aruments */
#include <stdio.h>
#include <stdlib.h> //exit
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>  //STDIN_FILENO
#define MAXLINE 4096 /* max line length */
static void err_doit(int errnoflag, int error, const char *fmt, va_list ap) {
    char buf[MAXLINE];
    vsnprintf(buf, MAXLINE - 1, fmt, ap);
    if (errnoflag)
        snprintf(buf + strlen(buf), MAXLINE - strlen(buf) - 1, ": %s",
                 strerror(error));
    strcat(buf, "\n");
    fflush(stdout); /* in case stdout and stderr are the same */
    fputs(buf, stderr);
    fflush(NULL); /* flushes all stdio output streams */
}
void err_sys(const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    err_doit(1, errno, fmt, ap);
    va_end(ap);
    exit(1);
}
#ifdef PATH_MAX
static long pathmax = PATH_MAX;
#else
static long pathmax = 0;
#endif
static long posix_version = 0;
static long xsi_version = 0;
/* If PATH_MAX is indeterminate, no guarantee this is adequate */
#define PATH_MAX_GUESS 1024
char *path_alloc(size_t *sizep) /* also return allocated size, if nonnull */
{
    char *ptr;
    size_t size;
    if (posix_version == 0)
        posix_version = sysconf(_SC_VERSION);
    if (xsi_version == 0)
        xsi_version = sysconf(_SC_XOPEN_VERSION);
    if (pathmax == 0) { /* first time through */
        errno = 0;
        if ((pathmax = pathconf("/", _PC_PATH_MAX)) < 0) {
            if (errno == 0)
                pathmax = PATH_MAX_GUESS; /* it's indeterminate */
            else
                err_sys("pathconf error for _PC_PATH_MAX");
        } else {
            pathmax++; /* add one since it's relative to root */
        }
    }
    /*
     * Before POSIX.1-2001, we aren't guaranteed that PATH_MAX includes
     * the terminating null byte.  Same goes for XPG3.
     */
    if ((posix_version < 200112L) && (xsi_version < 4))
        size = pathmax + 1;
    else
        size = pathmax;
    if ((ptr = malloc(size)) == NULL)
        err_sys("malloc error for pathname");
    if (sizep != NULL)
        *sizep = size;
    return (ptr);
}
int main(int argc, char **argv) {
    char *ptr;
    size_t size;
    /*    if (chdir("/usr/spool/uucppublic") < 0)*/
    if (chdir("/tmp") < 0)
        err_sys("chdir failed");
    ptr = path_alloc(&size); /* our own function */
    if (getcwd(ptr, size) == NULL)
        err_sys("getcwd failed");
    printf("cwd = %s\n", ptr);
    exit(0);
}
