/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : eg_08_06_mem_ls.c
* Author : gongchengra@gmail.com
* Purpose :
* Creation Date : 2020-04-22
* Last Modified : 2020-04-22 10:40:02+0800
_._._._._._._._._._._._._._._._._._._._._.*/
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#define NAME_MAX 256
#define MAX_PATH 1024 * 1024
typedef struct {
    long ino;
    char name[NAME_MAX];
} Dirent;
typedef struct {
    int fd;
    Dirent d;
} DIR;
DIR *opendir(char *dirname);
Dirent *readdir(DIR *dfd);
void dirwalk(char *dir, void (*fcn)(char *)) {
    char name[MAX_PATH];
    Dirent *dp;
    DIR *dfd;
    if ((dfd = opendir(dir)) == NULL) {
        fprintf(stderr, "dirwalk can't open %s\n", dir);
        return;
    }
    while ((dp = readdir(dfd)) != NULL) {
        if (strcmp(dp->name, ".") == 0 || strcmp(dp->name, "..") == 0) {
            continue;
        }
        if (strlen(dir) + strlen(dp->name) + 2 > sizeof(name)) {
            fprintf(stderr, "dirwalk: name %s/%s too long\n", dir, dp->name);
        } else {
            sprintf(name, "%s/%s", dir, dp->name);
            (*fcn)(name);
        }
    }
}
void fsize(char *name) {
    struct stat stbuf;
    if (stat(name, &stbuf) == -1) {
        fprintf(stderr, "fsize can't access %s\n", name);
        return;
    }
    if ((stbuf.st_mode & S_IFMT) == S_IFDIR) {
        dirwalk(name, fsize);
    }
    printf("%8lld %s\n", stbuf.st_size, name);
}
int main(int argc, char **argv) {
    if (argc == 1) {
        fsize(".");
    } else {
        while (--argc > 0) {
            fsize(*++argv);
        }
    }
    return 0;
}
