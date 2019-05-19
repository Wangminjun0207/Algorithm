#include <fstream>
#include "Predefine.h"
#include <cstdlib>

// 初始化有权网
void initNetwork(Network &network)
{
    std::ifstream file;
    file.open("data.txt",std::ios::in);
    if(!file.is_open())
    {
        std::cout << "Error opening file!" << std::endl;
        exit(1); // 异常退出
    }
    int it = 0;
    file >> network.n;
    for(int it=0; it<network.n; it++)
    {
        for(int j=0; j<network.n; j++)
        {
            file >> network.w[it][j];
        }
    }
}
