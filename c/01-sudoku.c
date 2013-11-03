#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//棋盘数组,[i][j]=k表示第i个行，第j列存放数字k
int mvarArrBox[9][9];

//预置数组
//2006-10-12 改为使用bit做标志
//mvarArrPreBox[i]的第j位上为1，表示i,j上有数
unsigned short int mvarArrPreBox[9];

/*
   小方块标志数组,mvarSmallBox[i]第j位
   表示第i个小方块中，数字j出现的个数
   2006-10-12 改为使用bit做标志
   */
unsigned short int mvarSmallBox[9];

/*
   列标志数组,mvarArrColumns[i]第j位表示
   第i列中，数字j出现的个数
   2006-10-12 改为使用bit做标志
   */
unsigned short int mvarArrColumns[9];

/*
   行标志数组,mvarArrRows[i][j]表示第i行中，数字j+1出现的个数
   2006-10-12 改为使用bit做标志
   */
unsigned short int mvarArrRows[9];



//函数声明
void Init();
void Usage(char *programName);
bool ReadDat(FILE *input);
void GoSearch();
void output();
bool fillin(int i, int j, int k);
void Remove(int i,int j);

//新加的位操作函数
bool setbit(unsigned short int intArr[], int i,int j ,bool k);
bool getbit(unsigned short int intValue, int j );

//初始化
void Init()
{
    int i,j;

    for (i=0;i<9;i++)
    {
        for (j=0;j<9;j++)
        {
            mvarArrBox[i][j]=0;
        }
        mvarArrColumns[i]=0;
        mvarArrRows[i]=0;
        mvarSmallBox[i]=0;
    }
}

void Usage(char *programName)
{
    fprintf(stderr,"%s.exe Write By xmxoxo \nUsage:\n",programName);
    /* Modify here to add your usage message when the program is
     * called without arguments */
    printf("%s.exe [inputfile]\n",programName);
} 

/* returns the index of the first argument that is not an option; i.e.
   does not start with a dash or a slash
   */
int HandleOptions(int argc,char *argv[])
{
    int i,firstnonoption=0;

    for (i=1; i< argc;i++) {
        if (argv[i][0] == '/' || argv[i][0] == '-') {
            switch (argv[i][1]) {
                /* An argument -? means help is requested */
                case '?':
                    Usage(argv[0]);
                    break;
                case 'h':
                    Usage(argv[0]);
                    break;
                case 'H':
                    Usage(argv[0]);
                    break;
                    /* If the option -h means anything else
                     * in your application add code here 
                     * Note: this falls through to the default
                     * to print an "unknow option" message
                     */
                    /* add your option switches here */
                default:
                    fprintf(stderr,"unknown option %s\n",argv[i]);
                    break;
            }
            return -1;
        }
        else {
            firstnonoption = i;
            break;
        }
    }
    return firstnonoption;
}

//主函数
int main(int argc, char* argv[])
{
    /* handle the program options */
    HandleOptions(argc,argv);
    /* The code of your application goes here */

    FILE *input_file;
    char input_file_name[81];

    if (argc == 1) 
    {
        //没有带参数则直接寻找dat.txt文件
        strcpy(input_file_name,"dat.txt");
    }
    if (argc>1)
    {
        strcpy(input_file_name,argv[1]);
    }
    //打开文件 r表示读，b表示二进制方式
    input_file=fopen(input_file_name,"rb");
    if (input_file==NULL)
    {
        printf("Input file name? ");
        scanf("%s",input_file_name);
        //打开文件 r表示读，b表示二进制方式
        input_file=fopen(input_file_name,"rb");
        if (input_file==NULL)
        {
            printf("Fatal error opening files.\n");
            return 1;
        }
    }


    //初始化
    Init();

    //读数据
    bool blnRet=ReadDat(input_file);
    fclose(input_file);
    //判断初始数据是否正确;
    if (!blnRet)
    {
        printf("Read Dat Error!\n");
        output();
        return 0;
    }
    //输出初始状态
    printf("初始状态：\n");
    output();

    //搜索
    GoSearch();

    return 0;
}

//读取初始数据
bool ReadDat(FILE *input)
{
    unsigned int character;
    bool blnRet=0;
    int i=0;
    int j=0;

    while (true)
    {
        //读入一个字节的数
        character=getc(input)-48; //'0';
        //如果是数字
        if (character>=0 && character<=9)
        {
            //放到棋盘数组中
            //非0,则在预置数组中做标志;
            if (character!=0)
            {
                if (!fillin(i,j,character))
                    return 0;
                setbit(mvarArrPreBox,i,j+1,1);
            }
            if (++j==9)
            {
                if (++i==9)
                    break;
                j=0;
            }
        }
        if (feof(input)) break;
    }
    return 1;
}

//搜索结果
void GoSearch()
{
    int Total=0;
    int i=0;
    int j=0;
    int k=0;
    bool bFind=false;
    while (true)
    {
        if (i<0 || j<0)
        {
            printf("共找到%d个结果\n",Total);
            return;
        }
        //超出位置了？
        if (i>8 || j>8)
        {
            //是，表示找到一个结果，
            printf("第%d个结果：\n",++Total);
            //输出结果；
            output ();
            printf("\n");
            //要找下一个结果吗？
            //if (AllResult)
            if (true)
            { 
                //要，继续返回，如何返回？
                i=8;
                j=9;
                //回到上一个非预置位置
                do 
                {
                    if (--j<0)
                    {
                        j=8;
                        i--;
                    }
                    if (i<0)
                        break;
                }
                while (getbit(mvarArrPreBox[i],j+1));

            }
            else
            {
                return;
            }
        }
        else
        {
            //否，
            if (getbit(mvarArrPreBox[i],j+1))
                //是预置位置吗？
            {
                //是
                //到下一个非预置位置
                do 
                {
                    if (++j==9)
                    {
                        j=0;
                        i++;
                    }
                    if (i>8) 
                        break;
                }
                while (getbit(mvarArrPreBox[i],j+1));
                //printf("前进-->[%d][%d]=%d\n",i,j,mvarArrBox[i][j]);

            }
            //否
            {
                //找一个可填的数并写入
                bFind=false;
                //读出当前位置值为基数
                for (k=mvarArrBox[i][j]+1;k<=9;k++)
                {
                    if (fillin (i,j,k))
                    {
                        bFind=true;
                        break;
                    }
                }
                //找到了吗？
                if (bFind)
                {
                    //是
                    //输出调试信息
                    //printf("填入,[%d][%d]=%d\n",i,j,mvarArrBox[i][j]);
                    //到下一个非预置位置
                    do 
                    {
                        if (++j==9)
                        {
                            j=0;
                            i++;
                        }
                        if (i>8)
                            break;
                    }
                    while ( getbit(mvarArrPreBox[i],j+1));
                    //printf("前进-->[%d][%d]=%d\n",i,j,mvarArrBox[i][j]);
                }
                else
                {
                    //没有能填入的数字
                    //清空当前位置的值
                    Remove(i,j);
                    //输出调试信息
                    //printf("清空,[%d][%d]\n",i,j);
                    //回到上一个非预置位置
                    do 
                    {
                        if (--j<0)
                        {
                            j=8;
                            i--;
                        }
                        if (i<0)
                            break;
                    }
                    while (getbit(mvarArrPreBox[i],j+1));
                    //printf("返回<--[%d][%d]=%d\n",i,j,mvarArrBox[i][j]);
                }
            }
        }
    }
}

/*
   位操作函数
   将数组中第i个数的第j位置k(k=0,1)
   设置成功返回true;否则返回false;
   */
bool setbit(unsigned short int intArr[], int i,int j ,bool k)
{
    unsigned short int intTmp;
    //构造运算符;
    //intTmp=(k)?(1<<(j-1)):0xFFFF-(1<<(j-1));
    if (k)
    {
        intTmp=1<<(j-1);
        //设置为1
        intArr[i] |= intTmp;
    }
    else
    {
        intTmp=0xFFFF-(1<<(j-1));
        //设置为0
        intArr[i] &= intTmp;
    }
    return 1;
}

/*
   判断intValue的第j位状态
   返回0或者1;
   */
bool getbit(unsigned short int intValue, int j )
{
    //unsigned int是4字节，32bit;
    //unsigned short int是2字节，16bit; 
    //左移，去掉左边位；
    intValue<<=(16-j);
    //右移,去掉右边位;
    intValue>>=15;
    return (intValue)?true:false;
}

/*
   将K填入[i][j]位置
   如果检查出已重复，则不填入值，并返回false，
   否则填入并返回true;
   */
bool fillin(int i, int j, int k)
{
    //int intPre=0;
    if (!getbit(mvarArrRows[i],k)
            && !getbit(mvarArrColumns[j],k)
            && !getbit(mvarSmallBox[(i/3)+(j/3)*3],k) )
    {
        //移除原来的值
        Remove(i,j);
        //填写到当前空格
        mvarArrBox[i][j]=k;

        //更新行列及小方格的统计
        setbit(mvarArrRows,i,k,1);
        setbit(mvarArrColumns,j,k,1);
        setbit(mvarSmallBox,(i/3)+(j/3)*3,k,1);
        return true;
    }
    else
    {
        return false;
    }
}

/*
   清除[i][j]位置的数,即设为0
   */
void Remove(int i,int j)
{
    int k=0;
    //读出值
    k=mvarArrBox [i][j];
    //清空位置
    mvarArrBox [i][j]=0;

    //更新行列及小方格的统计
    if (k>0)
    {
        setbit(mvarArrRows,i,k,0);
        setbit(mvarArrColumns,j,k,0);
        setbit(mvarSmallBox,(i/3)+(j/3)*3,k,0);
    }
    return ;
}

//输出结果
void output()
{
    int i,j;
    printf(" 0 1 2 3 4 5 6 7 8 \n");
    printf(" ┏━┯━┯━┳━┯━┯━┳━┯━┯━┓\n");
    for (i=0;i<9;i++)
    {
        printf("%d┃",i);
        for (j=0;j<9;j++)
        {
            if (!mvarArrBox[i][j])
                printf(" ");
            else
            {
                if (getbit(mvarArrPreBox[i],j+1))
                    printf("*%d",mvarArrBox[i][j]);
                else
                    printf("%2d",mvarArrBox[i][j]);
            }

            if ((j+1)%3==0)
                printf("┃");
            else
                printf("│");
        }
        printf("\n");
        if (i!=8)
            if ((i+1) % 3==0)
                printf(" ┣━┿━┿━╋━┿━┿━╋━┿━┿━┫\n");
            else
                printf(" ┠─┼─┼─╂─┼─┼─╂─┼─┼─┨\n");
    }
    printf(" ┗━┷━┷━┻━┷━┷━┻━┷━┷━┛\n");
}
