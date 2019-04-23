/* 给定长度为 n 的整数数组 nums，其中 n > 1，返回输出数组 output ，
其中 output[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积。

示例:
输入: [1,2,3,4]
输出: [24,12,8,6]
说明: 请不要使用除法，且在 O(n) 时间复杂度内完成此题。 */

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len  = nums.size();
        vector<int> output(len);
        int left_val = 1;
        int right_val = 1;
		// 将nums[i]之前的乘积乘到nums[i]上
        for(int i=0;i<len;i++)
        {
            output.at(i) = left_val;
            left_val *= nums.at(i);
        }
		// 将nums[j]之后的乘积乘到nums[j]上
        for(int j=len-1;j>=0;j--)
        {
            output.at(j) *= right_val;
            right_val *= nums.at(j);
        }
        return output;
    }
};