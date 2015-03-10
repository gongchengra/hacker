#include <stdio.h>
#include <stdlib.h>
#define max 10000
int (*openfile)[max](const char filename[])
{
    int size=0;
    long (*data)[max];
    FILE *file = fopen ( filename, "r" );
    if ( file != NULL )
    {
        char line [ 128 ]; /* or other suitable maximum line size */
        while ( fgets ( line, sizeof line, file ) != NULL ) /* read a line */
        {
            (*data)[size]=(long) strtol(line, (char **)NULL, 10);
        }
        fclose ( file );
    }
    else
    {
        perror ( filename ); /* why didn't the file open? */
    }
    return data;
}
int main ( void )
{
    //static const char filename[] = "data1.txt";
    int flag=0,i=0,j=0,k=0,size1=0,size2=0,size3=0;
    int (*data1)[max],(*data2)[max],(*data3)[max];
    //long data1[max],data2[max],data3[max];
    data1=openfile("data1.txt");
    data2=openfile("data2.txt");
    data3=openfile("data3.txt");
    FILE *file4;
    if((file4=fopen("entities.txt","wb+"))==NULL)
    {
        printf("Cannot open file strike any key exit!");
        getchar();
        exit(1);
    }
    else
    {
        for(i=0;i<size2;i++)
        {
            flag = 0;
            for(j=0;j<size1;j++)
            {
                if(data1[j]==data2[i])
                {
                    //printf("In\n");
                    fprintf(file4,"%ld\n",data3[j]);
                    k++;
                }
                else
                {
                    flag++;
                }
            }
            if(flag==size1)
            {
                printf("%ld is not in data1\n",data2[i]);
            }
        }
    }
    fclose( file4 );
    //printf("%d\n%d\n%d\n",size1,size2,k);
    return 0;
}
