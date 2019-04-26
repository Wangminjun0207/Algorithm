/* 有两种特殊字符。第一种字符可以用一比特0来表示。第二种字符可以用两比特(10 或 11)来表示。
现给一个由若干比特组成的字符串。问最后一个字符是否必定为一个一比特字符。给定的字符串总是由0结束。

示例 1:
输入: 
bits = [1, 0, 0]
输出: True
解释: 
唯一的编码方式是一个两比特字符和一个一比特字符。所以最后一个字符是一比特字符。
示例 2:
输入: 
bits = [1, 1, 1, 0]
输出: False
解释: 
唯一的编码方式是两比特字符和两比特字符。所以最后一个字符不是一比特字符。 */

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        while(bits.size()>1)
        {
			// 如果本位是0直接从向量容器删除
            if(bits.at(0)==0)
            {
                bits.erase(bits.begin());
            }
			// 如果本位是1直接从向量容器删除两位
            else
            {
                bits.erase(bits.begin());
                bits.erase(bits.begin());
            }
        }
        if(bits.size()==0)
        {
            return false;
        }
        else
        {
            if(bits.at(0)==0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
};