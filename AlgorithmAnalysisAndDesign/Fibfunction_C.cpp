#include <stdio.h>
int fib_func(int n)
{
	if(n==1 || n==2)
		return 1;
	else
		return fib_func(n-1) + fib_func(n-2);
}
int main()
{
	int i, sum = 0;
	printf("��40���ֵΪ��%d\n",fib_func(40));
	for(i=1; i<=40; i++)
		sum += fib_func(i); 
	printf("ǰ40���ֵΪ��%d\n",sum);
	return 0;
} 
