// StackFrame1.cpp : �鿴��������ʱ��ջ֡��
#include <iostream>

int func1(int i1, int i2, int i3, int i4)
{	int f1;
	f1=(i1+i2)-(i3+i4);
	return f1;
}
int main(int argc, char* argv[])
{	int a, b, c, d, f;
	a=125;  b=300;  c= -20;  d=250;
	f = func1(a,b,c,d);    //���öϵ㣬����ִ�в鿴����ִ��
	return 0;        // ���öϵ㣬�鿴����ִ�к���
}
