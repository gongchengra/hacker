#include <fcntl.h> /* flags for read and write */
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>  /* structure returned by stat */
#include <sys/types.h> /* typedefs */
#include <unistd.h>

#define NAME_MAX 14 // longest filename component;  system-dependent

typedef struct // portable directory entry:
{
    long ino;                // inode number
    char name[NAME_MAX + 1]; // name + '\0' terminator
} Dirent;

typedef struct // minimal DIR: no buffering, etc.
{
    int fd;   // file descriptor for directory
    Dirent d; // the directory entry
} DIR;

DIR *opendir(char *dirname);
Dirent *readdir(DIR *dfd);
void closedir(DIR *dfd);
void fsize(char *);

// from https://github.com/caisah/K-and-R-exercises-and-examples
// gcc -ansi eg_08_06_fsize.c -o eg_08_06_fsize.exe
/* print file sizes */
int main(int argc, char **argv) {
    if (argc == 1) /* default: current directory */
        fsize(".");
    else
        while (--argc > 0)
            fsize(*++argv);

    return 0;
}

void dirwalk(char *, void (*fcn)(char *));

/* fsize: print size of file "name" */
void fsize(char *name) {
    struct stat stbuf;

    if (stat(name, &stbuf) == -1) {
        fprintf(stderr, "fsize: can't access %s\n", name);
        return;
    }
    if ((stbuf.st_mode & S_IFMT) == S_IFDIR)
        dirwalk(name, fsize);
    printf("%8lld %s\n", stbuf.st_size, name);
}

#define MAX_PATH 1024

/* dirwalk: apply fcn to all files in dir */
void dirwalk(char *dir, void (*fcn)(char *)) {
    char name[MAX_PATH];
    Dirent *dp;
    DIR *dfd;

    if ((dfd = opendir(dir)) == NULL) {
        fprintf(stderr, "dirwalk: can't open %s\n", dir);
        return;
    }
    while ((dp = readdir(dfd)) != NULL) {
        if (strcmp(dp->name, ".") == 0 || strcmp(dp->name, "..") == 0)
            continue; /* skip self and parent */
        if (strlen(dir) + strlen(dp->name) + 2 > sizeof(name))
            fprintf(stderr, "dirwalk: name %s/%s too long\n", dir, dp->name);
        else {
            sprintf(name, "%s/%s", dir, dp->name);
            (*fcn)(name);
        }
    }
    closedir(dfd);
}
