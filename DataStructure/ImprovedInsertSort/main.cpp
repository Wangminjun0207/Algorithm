#include <iostream>
extern int InsertSort(int arr[], int len);
int main()
{
    int arr[10] = {-99, 12, 0, 45, 78, 700, 45, 100, -999, 10};
    InsertSort(arr,10);
    for(int i=0;i<10;i++)
    {
        std::cout << arr[i] << "  ";
    }
    std::cout << std::endl;
    return 0;
}
