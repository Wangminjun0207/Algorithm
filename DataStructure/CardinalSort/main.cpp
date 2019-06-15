/**
  * 键盘输入n个无符号整数，用链式基数排序实现由小到大
  * 排序，输出排序结果。提示：对于C语言32bit宽的unsigned类型，
  * 可以采用16进制形式来实现基数排序，即32bit共有8个16进制位，
  * 每个16进制位进行一趟分配和收集，共8趟。
  */


#include <iostream>
#include "Predefine.h"
extern int CardinalSort(Link *h);
extern int CreateLink(Link *h);
extern int Print(Link *h);

int main()
{
    Link *h = new Link();
    CreateLink(h);
    Print(h);
    CardinalSort(h);
    Print(h);
    return 0;
}
