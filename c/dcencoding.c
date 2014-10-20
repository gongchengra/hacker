#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i,j;
    char string[256];
    int result[512];
    for(j=0;j<512;j++){
        result[j]=0;
    }
    /*    long long encoding=0;*/
    printf("Enter string to encode:");
    scanf("%s",string);
/*    printf("%s",string);*/
    for(i=0;i<256 && string[i]!=0;i++){
        result[0] = result[0] + string[i];
        for(j=0;j<512 && result[j] !=0;j++){
            result[j] = result[j] * 256;
            if(result[j] > 9){
                result[j+1] = result[j+1] + result[j] / 10;
                result[j] = result[j] % 10;
            }
        }
    }
    for(j=512;j>0;j--){
        if(result[j] != 0){
            printf("%d ", result[j]);
        }
    }
    return 0;
}
