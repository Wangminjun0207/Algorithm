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
        std::cout << "�����ɹ�!\n";
    }
    else
    {
        std::cout << "����ʧ��!\n";
    }
    std::cout << "����������У�";
    Midorder(T);
    return 0;
}
