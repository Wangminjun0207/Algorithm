#include <iostream>
#include <fstream>
#include "sort.h"
#include <vector>

void Mgr()
{
    std::vector<int> arr_m;
    std::vector<int> arr_q;
    std::vector<int> arr_h;

    std::ifstream file;
    int num;
    file.open("input_merger.txt");
    while(file>>num)
    {
        arr_m.push_back(num);
    }
    file.close();
    file.open("input_quick.txt");
    while(file>>num)
    {
        arr_q.push_back(num);
    }
    file.close();
    file.open("input_heap.txt");
    while(file>>num)
    {
        arr_h.push_back(num);
    }
    file.close();
    std::vector<int> arr(arr_m);

    std::ofstream output;
    output.open("output.txt",std::ios::app);
    // ≤‚ ‘πÈ≤¢≈≈–Ú
    output << "Original array: ";
    output.close();
    Print(arr_m,10);
    MergerSort(arr_m, arr, 0, 9);
    output.open("output.txt",std::ios::app);
    output << "MergerSort:     ";
    output.close();
    Print(arr_m,10);

    // ≤‚ ‘øÏÀŸ≈≈–Ú
    output.open("output.txt",std::ios::app);
    output << "Original array: ";
    output.close();
    Print(arr_q,10);
    QuickSort(arr_q, 0, 9);
    output.open("output.txt",std::ios::app);
    output << "QuickSort:      ";
    output.close();
    Print(arr_q,10);

    // ≤‚ ‘∂—≈≈–Ú
    output.open("output.txt",std::ios::app);
    output << "Original array: ";
    output.close();
    Print(arr_h,10);
    HeapSort(arr_h, 10);
    output.open("output.txt",std::ios::app);
    output << "HeapSort:       ";
    output.close();
    Print(arr_h,10);
    output.close();
}
