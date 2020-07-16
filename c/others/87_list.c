/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : 87_list.c
* Author : gongchengra@gmail.com
* Purpose :
* Creation Date : 2020-07-07
* Last Modified : 2020-07-10 15:13:37+0800
_._._._._._._._._._._._._._._._._._._._._.*/
#include <stdio.h>
int main(int argc, char **argv){
    int i, j, k, l;
    for(i=20; i < 100;i++){
        for(j=i+1;j < 101;j++){
            for(k=i;k< 100;k++){
                for(l=k+1;l< 101;l++){
                    printf("%10.8f = %d %d * %d %d \n", (1.0*i*k/(j*l)), i, j, k, l);
                }
            }
        }
    }
}

