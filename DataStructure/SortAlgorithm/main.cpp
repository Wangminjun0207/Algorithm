#include <iostream>
#include "Sort.h"

int main()
{
    int arr_test[10] = {45,12,0,15,45,8,-89,454,548,-7};
    std::vector<int> arr(arr_test,arr_test+10); // 使用数组初始化容器
    Sort<int> sort_test;

/*     std::vector<int> arr_radix(arr);
 *     sort_test.radixSort(arr_radix);
 *
 *     std::vector<int> arr_shell(arr);
 *     sort_test.shellSort(arr_shell);
 *
 *     std::vector<int> arr_insert(arr);
 *     sort_test.insertSort(arr_insert);
 *
 *     std::vector<int> arr_quick(arr);
 *     sort_test.quickSort(arr_quick);
 */

    std::vector<int> arr_bubble(arr);
    sort_test.bubbleSort(arr_bubble);

/*     std::vector<int> arr_merger(arr);
 *     sort_test.mergerSort(arr_merger);
 *
 *     std::vector<int> arr_heap(arr);
 *     sort_test.heapSort(arr_heap);
 *
 *     std::vector<int> arr_bucket(arr);
 *     sort_test.bucketSort(arr_bucket);
 *
 *     std::vector<int> arr_bogo(arr);
 *     sort_test.bogoSort(arr_bogo);
 */

    return 0;
}
