#include <iostream>
#include <ctime>
#include "Predefine.h"

extern void LinkedSort(NodePtr h);

int main()
{
    NodePtr h = new Node();
    NodePtr link = h;
    srand(time(0)); // 产生随机数
    for(int i=0;i<10;i++)
    {
        NodePtr p = new Node();
        p->next = NULL;
        p->key = 10 - i;
        link->next = p;
        link = p;
    }
    LinkedSort(h);
    for(NodePtr p=h->next;p!=NULL;p=p->next)
    {
        std::cout << p->key << "  ";
    }
    return 0;
}
