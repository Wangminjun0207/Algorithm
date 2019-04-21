#include<stdio.h>
int main() 
{
    int max = 0, count = 1,n = 10;
    int b, c;
    int a[] = {10,5,7,8,54,55,12,45,26,56};
    int i, j;
    for(i = 0; i < n; i++)
	{
        b = a[i];
        for(j = i + 1; j < n; j++)
		{
            if(b < a[j]) {
                b = a[j];
                count++;
            }
            else break;
        }
        if(max < count)
		{
            max = count;
            c = i;  // 记录递增序列开始的位置 
        }
        count = 1;
    }
    printf("%d ",a[c]);
    b = a[c];
    for(i = c + 1; i < n; i++)
	{
        if(b < a[i])
		{
            b = a[i];
            printf("%d ", b);
        }
        else break; // 如果递增序列断开则退出循环 
    }
    return 0;
}
