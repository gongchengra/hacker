/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : 83_opendir.c
* Author : gongchengra@gmail.com
* Purpose :
* Creation Date : 2020-04-24
* Last Modified : 2020-04-24 13:53:11+0800
_._._._._._._._._._._._._._._._._._._._._.*/
#include <dirent.h>
#include <stdio.h>
void ls(char *dname) {
    struct dirent *pDirent;
    DIR *pDir;
    pDir = opendir(dname);
    if (pDir == NULL) {
        printf("Cann't open directory %s\n", dname);
        return;
    }
    while ((pDirent = readdir(pDir)) != NULL) {
        printf("%s\n", pDirent->d_name);
    }
    closedir(pDir);
}
int main(int argc, char **argv) {
    if (argc == 1) {
        ls(".");
    } else {
        while (--argc > 0) {
            ls(*++argv);
        }
    }
    return 0;
}
