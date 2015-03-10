#include <stdio.h>
#include <stdlib.h>
#define max 10000
int main ( void )
{
    //static const char filename[] = "data1.txt";
    int flag=0,i=0,j=0,k=0,size1=0,size2=0,size3=0;
    long data1[max],data2[max],data3[max];
    FILE *file1 = fopen ( "data1.txt", "r" );
    if ( file1 != NULL )
    {
        char line [ 128 ]; /* or other suitable maximum line size */
        while ( fgets ( line, sizeof line, file1 ) != NULL ) /* read a line */
        {
            //fputs ( line, stdout ); /* write the line */
            data1[size1]=(long) strtol(line, (char **)NULL, 10);
            //printf("%ld\n",data1[size1]);
            size1++;
            //fputs (line, stdout ); /* write the line */
        }
        fclose ( file1 );
    }
    else
    {
        perror ( "data1.txt" ); /* why didn't the file1 open? */
    }
    FILE *file2 = fopen ( "data2.txt", "r" );
    if ( file2 != NULL )
    {
        char line [ 128 ]; /* or other suitable maximum line size */
        while ( fgets ( line, sizeof line, file2 ) != NULL ) /* read a line */
        {
            //fputs ( line, stdout ); /* write the line */
            data2[size2]=(long) strtol(line, (char **)NULL, 10);
            //printf("%ld\n",data2[size2]);
            size2++;
            //fputs (line, stdout ); /* write the line */
        }
        fclose ( file2 );
    }
    else
    {
        perror ( "data2.txt" ); /* why didn't the file2 open? */
    }
    FILE *file3 = fopen ( "data3.txt", "r" );
    if ( file3 != NULL )
    {
        char line [ 128 ]; /* or other suitable maximum line size */
        while ( fgets ( line, sizeof line, file3 ) != NULL ) /* read a line */
        {
            //fputs ( line, stdout ); /* write the line */
            data3[size3]=(long) strtol(line, (char **)NULL, 10);
            size3++;
            //fputs (line, stdout ); /* write the line */
        }
        fclose ( file3 );
    }
    else
    {
        perror ( "data3.txt" ); /* why didn't the file3 open? */
    }

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
