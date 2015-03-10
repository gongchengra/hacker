#include <stdio.h>

int main(void)
{
    int days = 360;

    //“劝学网”三字的ASCII码是“C8B0”“D1A7”“CDF8”
    printf("\xC8\xB0\xD1\xA7\xCD\xF8\t小雅\n");   //显示：劝学网{TAB}小雅

    printf("北京奥运还有: %d天\n", days);
    printf("\a\a");          //“嘟嘟”

    //以下三行写在同一行
    printf("%s", "这是C语言");
    printf("教程\t");
    printf("作者：%s\n","小雅");

    //360分别以整数、小数、科学计数法显示
    printf("整数:%d\n小数:%f\n科学:%e\n",days,(float)days,(double)days);

    //以下控制字节长度
    printf("360用5个字节表示：[%5d]\n",days);   //[...]中共5字节
    printf("3.6保留2位整数2位小数：[%5.2f]\n",(float)days/100);   //[...]中2位整数2位小数，
    //外加小数点共5字节
    return 0;
}
