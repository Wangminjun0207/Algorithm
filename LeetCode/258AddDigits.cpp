/* 给定一个非负整数 num，反复将各个位上的数字相加，直到结果为一位数。
示例:
输入: 38
输出: 2 
解释: 各位相加的过程为：3 + 8 = 11, 1 + 1 = 2。 由于 2 是一位数，所以返回 2。 */

class Solution {
public:
    int addDigits(int num) {
		/* 下面代码等价于
		if(num>9)
		{
			if(num%9 != 0)
			{
				return num%9;
			}
			else
			{
				return num;
			}
		}
		else
		{
			return num;
		}*/
        return num > 9 ? num % 9 != 0 ? num % 9 : 9 : num;
    }
};