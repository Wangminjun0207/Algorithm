/*  题目：编写一个C语言程序段，其中包含结构体变量和对结构体成员变量的赋值然后通
 *  常运行调试手段（例如查看变量在内存中的地址、内蕴单元中的十六进制数据等等）。查看：
 * （1）	多字节数值型数据在内存中的存放顺序；
 * （2）	结构体变量的起始地址以及每个结构体成员变量的存储地址。
 */

#include <stdio.h>
#include <stdlib.h>
typedef struct test1{
    char ch;
    int bval;
    short aval;
    float cval;
}Test1;
#pragma pack (1)  //将结构体中的成员按1字节对齐
typedef struct test2{
    char ch;
    int bval;
    short aval;
    float cval;
}Test2;
#pragma pack ()   //取消自定义字节方式
int main()
{
    Test1 ts1;
    ts1.ch = 'a';
    ts1.bval = 1024;
    ts1.aval = 128;
    ts1.cval = 3.14;
    printf("sizeof(test1)=%d\n",sizeof(ts1));

    Test2 ts2;
    ts2.ch = 'a';
    ts2.bval = 1024;
    ts2.aval = 128;
    ts2.cval = 3.14;
    printf("sizeof(test2)=%d\n",sizeof(ts2));
    return 0;
}
