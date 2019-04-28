/* 观察定点数和浮点数的运算结果是否溢出 */ 
#include <stdio.h>
int main(int argc, char **aragv)
{
	short int a = 1;
	short int b = 32767; 
	float c = 3.4E38;
	float d = 3.4E10;
	short int e = a + b;
	printf("%d\n",e);
	float f = c + d;
	printf("%f\n",f);
	return 0;
}
