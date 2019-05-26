#include <iostream>
#include "Travel.h"

int main()
{
    Travel travel;
    std::cout << "深度优先搜索：";
    travel.DFSTravel();
    std::cout << "广度优先搜索：";
    travel.BFSTravel();
    return 0;
}
