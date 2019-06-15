#include <iostream>
extern void BubbleSort(int arr[], int n);
extern void InsertSort(int arr[], int low, int n);
int main()
{
    int arr[6] = {-99, 100, 0, 45, -1000, 98};
    InsertSort(arr,0,6);
    for(int i=0;i<6;i++)
    {
        std::cout << arr[i] << "  ";
    }
    std::cout << std::endl;
    /**
    BubbleSort(arr,6);
    for(int i=0;i<6;i++)
    {
        std::cout << arr[i] << "  ";
    }
    std::cout << std::endl;
    */
    return 0;
}
