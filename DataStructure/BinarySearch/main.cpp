#include <iostream>
#include <vector>
extern int BinarySearch(std::vector<int> &a, int key);
int main()
{
    std::vector<int> arr;
    for(int i=1;i<20;i++)
    {
        arr.insert(arr.end(),i);
    }
    int it = BinarySearch(arr,9);
    std::cout << it << std::endl;
    return 0;
}
