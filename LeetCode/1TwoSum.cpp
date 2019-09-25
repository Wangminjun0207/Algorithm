/*
给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。

示例:

给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> hashmap;
        vector<int> result(2);
        for(int i=0;i<nums.size();i++)
        {
             hashmap.insert(pair<int,int>(nums[i],i));
        }
        
        for(int i=0; i<nums.size();i++)
        {
            int complement = target - nums.at(i);
            if(hashmap.find(complement)!=hashmap.end() && hashmap.find(complement)->second!=i)
            {
                result.at(0) = i;
                result.at(1) = hashmap.find(complement)->second;
                break;
            }
        }
        return result;
    }
};
