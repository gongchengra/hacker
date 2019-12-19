#include<stdio.h>
int main(){
    FILE *fp, *rp;

    fp=fopen("myfile2.log","w");
    fputs("hello c programming",fp);
    fclose(fp);

    rp=fopen("eg_07_06_cat.c","r");
    char text[300];
    printf("%s",fgets(text,200,rp));
    fclose(rp);
    return 0;
}
