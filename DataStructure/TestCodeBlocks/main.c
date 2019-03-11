/* Name:TestCodeBlockss
 * Copyright:null
 * Author:Wang Minjun
 * Date: 11/03/19 11:20
 * Description:从键盘输入数据，建立带附加头结点的单向链表；
 *             按节点连接次数输出数据节点的数据；
 *             实现数据节点按节点数据从小到大的次序连接；
 *             按节点连接次数输出排序后的节点数据；
 *             实现数据节点逆序连接；
 *             按节点连接次序输出逆序连接后的数据节点的数据；
 */

#include <stdio.h>
#include <stdlib.h>
#include "predefine.h"

/* 在此处调试的时候遇到问题:C语言文件定义的函数在
 * C++文件中用extern声明的时候出现错误；通过某度的
 * 查询得知是编译器对于C语言和c++函数编译时的命名不
 *一样， 所以导致出现错误
 */
extern void display(NodePtr h);
extern NodePtr create();
extern void reverse(NodePtr h);
extern void sort(NodePtr h);

int main()
{
    NodePtr h;
    printf("输入若干非零整数，直到输入零时停止，建立单向链表：");
    h = create();
    printf("原链接次序：");
    display(h);
    printf("\n");
    sort(h);
    printf("排序后次序：");
    display(h);
    printf("\n");
    reverse(h);
    printf("逆序后次序：");
    display(h);
    printf("\n");
    return 0;
}
