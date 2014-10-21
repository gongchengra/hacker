#include <stdio.h>
#include <stdlib.h>
#define MAXLENGTH 100
#define RESULTLENGTH 300
#define dc_base 256
int main()
{
    int i,j;
    char flag=0;
    char string[MAXLENGTH];
    int result[RESULTLENGTH];
    for(j=0;j<RESULTLENGTH;j++){
        result[j]=0;
    }
    printf("Enter string to encode:");
    scanf("%s",string);
    /*    printf("%ld\n",sizeof(string)/sizeof(char));*/
    /*    printf("%s",string);*/
    for(i=0;i<MAXLENGTH && string[i]!='\0';i++){
        for(j=0;j<RESULTLENGTH-1;j++){
            result[j] = result[j] * dc_base;
        }
        result[0] = result[0] + string[i];
        for(j=0;j<RESULTLENGTH-1;j++){
            if(result[j] > 9){
                result[j+1] = result[j+1] + (result[j] / 10);
                result[j] = result[j] % 10;
            }
        }
    }
    while(j>=0){
        if(result[j]!=0) flag = 1;
        if(flag == 1) printf("%d", result[j]);
        j--;
    }
    printf("\n");
    return 0;
}
