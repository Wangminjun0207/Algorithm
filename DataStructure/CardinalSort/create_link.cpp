#include "Predefine.h"

// 创建链表
int CreateLink(Link *h)
{
    unsigned int num;
    NodePtr ptr = new Node(); // 头结点
    h->ptr = ptr;
    // 输入若干unsigned int 类型的数值
    std::cin >> num;
    while(num!=0)
    {
        NodePtr p = new Node();
        p->key = num;
        p->next = NULL;
        ptr->next = p;
        ptr = p;
        std::cin >> num;
    }
    // 指针数组置空
    for(int i=0;i<16;i++)
    {
        NodePtr p = new Node();
        h->Sort[i] = p;
        h->Sort[i]->next = NULL;
    }
    return 1;
}
