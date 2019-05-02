// StackFrame1.cpp : 查看函数调用时的栈帧。
#include <iostream>

int func1(int i1, int i2, int i3, int i4)
{	int f1;
	f1=(i1+i2)-(i3+i4);
	return f1;
}
int main(int argc, char* argv[])
{	int a, b, c, d, f;
	a=125;  b=300;  c= -20;  d=250;
	f = func1(a,b,c,d);    //设置断点，单步执行查看函数执行
	return 0;        // 设置断点，查看函数执行后结果
}
