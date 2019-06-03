/***************************************************************
* 实现 int sqrt(int x) 函数。
* 计算并返回 x 的平方根，其中 x 是非负整数。
* 由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。
* 示例 1:
* 输入: 4
* 输出: 2
* 示例 2:
* 输入: 8
* 输出: 2
* 说明: 8 的平方根是 2.82842..., 
*      由于返回类型是整数，小数部分将被舍去
****************************************************************/
class Solution {
public:
    int mySqrt(int x) {
        // 由于超出int的表示范围，所以选用long
        long low = 0;
        long hight = x;
        long temp, temp1;
        long m = (low + hight) / 2;
        while(1)
        {
            temp = m * m; 
            temp1 = (m+1) * (m+1);
            // m 刚好就是x开方之后的整数
            if(temp<=x && temp1>x)
            {
                break;
            }
            // m大于x开方时候的整数
            else if(temp>x){
                hight = m;
                m = (low + hight) / 2;
                continue;
            }
            // m+1小于x开方时候的整数
            else if(temp1<x){
                low = m;
                m = (low + hight) / 2;
                continue;
            }
            // m+1等于x开方时候的整数
            else if(temp1==x){
                m = m + 1;
                break;
            }
        }
        return m;
    }
};