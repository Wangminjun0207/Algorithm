/* 给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。
最高位数字存放在数组的首位， 数组中每个元素只存储一个数字。
你可以假设除了整数 0 之外，这个整数不会以零开头。

示例 1:
输入: [1,2,3]
输出: [1,2,4]
解释: 输入数组表示数字 123。
示例 2:

输入: [4,3,2,1]
输出: [4,3,2,2]
解释: 输入数组表示数字 4321。 */

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int ival = digits.size() - 1;
		// 如果下面一条语句这样写，会出现下标越界，导致运算结果错误
		// while(digits[ival]==9 && ival>=0)
        while(ival>=0 && digits[ival]==9)
        {
            digits[ival] = 0;
            ival--;
        }
        if(ival>=0)
        {
            digits[ival] += 1;
        }
        else
        {
            // 如果数组所有元素均为9，则在最前面添加以为，赋值为1
            digits.insert(digits.begin(),1);
        }
        return digits;
    }
};