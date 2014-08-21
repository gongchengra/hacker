/* 大文件统计
 * 文件大概有100~5000W行不等的数据，第一行是总行数，从第二行开始每行是一个家庭的身
 * 份证号码（固定18位）用逗号分隔。要求输出是生日相同的人最多的那天的总出生人数。
 * 1. generate id numbers to a file.
 * 2. calculate the number.
 * */
#include <stdio.h>

