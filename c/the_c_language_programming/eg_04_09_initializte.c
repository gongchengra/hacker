#include <stdio.h>
#include <string.h>
int main(){
    // the k&r book is not correct in section 4.9 anymore.
    // char test = "hello world" wouldn't work.
    char t1[] = {'h','e','l','l','o',' ','w','o','r','l','d','\0'};
    char t2[] = "hello world";
    printf("The length of '%s' is %ld.\n", t1, strlen(t1));
    printf("The length of '%s' is %ld.\n", t2, strlen(t2));
}
