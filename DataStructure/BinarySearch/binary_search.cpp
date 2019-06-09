#include <vector>
int BinarySearch(std::vector<int> &a, int key)
{
    /** \brief 使用二分法查找满足ai-1<key且ai>=key的i值
     *
     * \param a 关键字递增有序序列
     * \param key 给定关键字
     * \return 满足要求的i值，没有返回-1
     *
     */
    int low = 0;
    int len = a.size();
    int high = len - 1;
    int middle;
    // 不满足要求返回-1
    if(key>a.at(high) || key<=a.at(low))
    {
        return -1;
    }
    while(low<=high)
    {
        middle = (low + high) / 2;

        // 如果刚好满足要求，返回位置
        if(a.at(middle)>=key && a.at(middle-1)<key)
        {
            return middle;
        }
        // 小于则在后半部分查找
        else if(a.at(middle)<key){
            low = middle + 1;
            middle = (low + high) / 2;
        }
        // 大于则在前半部分查找
        else if(a.at(middle-1)>=key){
            high = middle - 1;
            middle = (low + high) / 2;
        }
    }
    return middle;
}
