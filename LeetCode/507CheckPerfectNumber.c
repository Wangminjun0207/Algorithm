/* 对于一个 正整数，如果它和除了它自身以外的所有正因子之和相等，我们称它为“完美数”。
给定一个 正整数 n， 如果他是完美数，返回 True，否则返回 False
示例：
输入: 28
输出: True
解释: 28 = 1 + 2 + 4 + 7 + 14 */

bool checkPerfectNumber(int num) {
    int sum = 0;
    if(num%2==0)
    {
        for(int i=1;i<=num/2;i++)
        {
            if(num%i==0)
                sum += i;
        }
    }
    if(!sum || sum!=num)// 如果num为0，也返回false
        return false;
    else
        return true;
}