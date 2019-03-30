/* 给定一个整数，写一个函数来判断它是否是 3 的幂次方。
示例 1:
输入: 27
输出: true
示例 2:
输入: 0
输出: false
示例 3:
输入: 9
输出: true
示例 4:
输入: 45
输出: false */

bool isPowerOfThree(int n) {
    if(n<3)
    {
        if(n==1) //任何数的0次幂都为1
            return true;
        else
            return false;
    }
    long int sum = 1;
    while(sum<=n)
    {
        sum = sum * 3;
        if(sum==n)
            return true;
    }
    return false;
}