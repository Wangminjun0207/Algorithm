/*����һ��ż�����ȵ����飬���в�ͬ�����ִ����Ų�ͬ������ǹ���ÿһ�����ִ���һ���ǹ�����
��Ҫ����Щ�ǹ�ƽ���ָ�һ���ܵܺ�һ�����á��������ÿ��Ի�õ�����ǹ�����������
ʾ�� 1:
����: candies = [1,1,2,2,3,3]
���: 3
����: һ��������������ǹ���ÿһ�ֶ���������
     ���ŷ��䷽�������û��[1,2,3],�ܵ�Ҳ���[1,2,3]������ʹ���û���ǹ�����������ࡣ*/

#include <stdio.h>
int distributeCandies(int* candies, int candiesSize) {
    int n, nKind;
    int i, j;
    n = 100003;
    nKind = 0;
    for(i=0;i<candiesSize;i++)
    {
        if(n!=candies[i] && 100001!=candies[i])
        {
            nKind++;
            n = candies[i];
            for(j=i+1;j<candiesSize;j++)
            {
                if(n==candies[j])
                    candies[j] = 100001;
            }
        }
    }
    if(nKind>candiesSize/2)
        return candiesSize/2;
    else
        return nKind;
}
int main()
{
	int n;
	int a[10] = {1,1,1,1,2,2,2,3,3,3};
	n = distributeCandies(a,10);
	printf("%d\n",n);
 } 
