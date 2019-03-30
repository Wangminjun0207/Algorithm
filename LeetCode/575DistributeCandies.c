/*给定一个偶数长度的数组，其中不同的数字代表着不同种类的糖果，每一个数字代表一个糖果。你
需要把这些糖果平均分给一个弟弟和一个妹妹。返回妹妹可以获得的最大糖果的种类数。
示例 1:
输入: candies = [1,1,2,2,3,3]
输出: 3
解析: 一共有三种种类的糖果，每一种都有两个。
     最优分配方案：妹妹获得[1,2,3],弟弟也获得[1,2,3]。这样使妹妹获得糖果的种类数最多。*/

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
