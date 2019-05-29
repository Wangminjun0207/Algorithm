#include <iostream>
#include <algorithm>
#define MAX_N 100 // ������

int data[MAX_N+1][MAX_N+1];
void InitData(int num);
int MaxNumber(int i, int j, int num, int *number);
int main()
{
    int num;
    std::cout << "���������β�����";
    std::cin >> num;
    InitData(num);
    int *number = data[num];
    std::cout << "max(1,1) = " << MaxNumber(1,1,num,number);
    return 0;
}

// ��ʼ������������
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

// ���������֮��
int MaxNumber(int i, int j, int num, int *number)
{
    /** ʱ�临�Ӷ�n^2, �ռ临�Ӷ�0 */
    for(int k=num-1;k>=i;k--)
    {
        for(int m=1;m<=k;m++)
        {
            number[m] = std::max(number[m], number[m+1]) + data[k][m];
        }
    }
    return number[j];
}
