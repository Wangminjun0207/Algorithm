//从键盘输入中缀表达式，建立操作数与运算符堆栈，计算并输出表达式的求值结果。
//基本要求：实现 +, -, *, /四个二元运算符以及（）；
//          操作数范围为0至9。
//提高要求：实现+, -两个一元运算符（即正、负号）；
//          操作数可为任意整型值（程序可不考虑计算溢出）。
//若两个整数相除，结果只保留整数商（余数丢弃）；每位同学可选择实现基本要求或者提高要求；程序可不处理表达式语法错误。

#include <stdio.h>
#include <stdlib.h>
#include "Predefine.h"
#define MAX_SIZE 20

int main()
{
    int top_optr = -1;   // 运算符栈顶指针
    int top_opnd = -1;   // 运算数栈顶指针
    char optr[MAX_SIZE]; // 操作符栈，最大容量MAX_SIZE
    int opnd[MAX_SIZE];  // 操作数栈，最大容量MAX_SIZE
    exTransform(optr,opnd,&top_optr,&top_opnd);
	printf("%d\n",get_top_number(opnd,&top_opnd));
    return 0;
}

