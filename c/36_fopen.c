#include <stdio.h>
void write(){
   FILE *fp;
   fp = fopen("test.log", "w");
   fprintf(fp, "This is testing for fprintf...\n");
   fputs("This is testing for fputs...\n", fp);
   fclose(fp);
}
void read(){
    FILE *fp;
    char buff[255];
    fp = fopen("test.log", "r");
    fscanf(fp, "%s", buff);
    printf("1 : %s\n", buff );
    fgets(buff, 255, (FILE*)fp);
    printf("2: %s\n", buff );
    fgets(buff, 255, (FILE*)fp);
    printf("3: %s\n", buff );
    fclose(fp);
}
int main() {
    write();
    read();
}
