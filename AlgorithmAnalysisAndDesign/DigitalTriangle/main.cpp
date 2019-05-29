#include <iostream>
#include <algorithm>
#define MAX_N 100 // 最大层数

int data[MAX_N+1][MAX_N+1];
void InitData(int num);
int MaxNumber(int i, int j, int num, int *number);
int main()
{
    int num;
    std::cout << "输入三角形层数：";
    std::cin >> num;
    InitData(num);
    int *number = data[num];
    std::cout << "max(1,1) = " << MaxNumber(1,1,num,number);
    return 0;
}

// 初始化数字三角形
void InitData(int num)
{
    for(int it=1; it<=num; it++)
    {
        for(int j=1;j<=it;j++)
        {
            std::cin >> data[it][j];
        }
    }
}

// 求最大数字之和
int MaxNumber(int i, int j, int num, int *number)
{
    /** 时间复杂度n^2, 空间复杂度0 */
    for(int k=num-1;k>=i;k--)
    {
        for(int m=1;m<=k;m++)
        {
            number[m] = std::max(number[m], number[m+1]) + data[k][m];
        }
    }
    return number[j];
}
