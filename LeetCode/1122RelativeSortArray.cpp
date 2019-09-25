/*
给你两个数组，arr1 和 arr2，

arr2 中的元素各不相同
arr2 中的每个元素都出现在 arr1 中
对 arr1 中的元素进行排序，使 arr1 中项的相对顺序和 arr2 中的相对顺序相同。未在 arr2 中出现过的元素需要按照升序放在 arr1 的末尾。

 

示例：

输入：arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
输出：[2,2,2,1,4,3,3,9,6,7,19]
 

提示：

arr1.length, arr2.length <= 1000
0 <= arr1[i], arr2[i] <= 1000
arr2 中的元素 arr2[i] 各不相同
arr2 中的每个元素 arr2[i] 都出现在 arr1 中 */


class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> result;
        vector<int>::iterator it; // arr2的迭代器
        int len = arr1.size(); // arr1的长度
        for(it=arr2.begin();it!=arr2.end();it++)
        {
            for(int i=0;i<len;i++)
            {
                if(arr1.at(i)!=-1 && arr1.at(i)==*it)
                {
                    result.push_back(arr1.at(i));
                    arr1.at(i) = -1; // 表示已经访问过
                }
            }
        }
        
        while(result.size()!=arr1.size())
        {
            int min = 1001;
            int index = 1001;
            for(int i=0;i<len;i++)
            {
                if(arr1.at(i)!=-1 && arr1.at(i)<=min)
                {
                    min = arr1.at(i);
                    index = i;
                }
            }
            result.push_back(arr1.at(index));
            arr1.at(index) = -1; // 表示已经访问过
        }
        return result;
    }
};