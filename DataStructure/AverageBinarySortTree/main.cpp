#include <iostream>
#include "Predefine.h"
extern int CreateBST(BSTree &T,int n);
extern int Midorder(BSTree T);
int main()
{
    BSTree T=NULL;
    int k;
    std::cin >> k;
    if(CreateBST(T,k))
    {
        std::cout << "建树成功!\n";
    }
    else
    {
        std::cout << "建树失败!\n";
    }
    std::cout << "中序遍历序列：";
    Midorder(T);
    return 0;
}
