#include "Predefine.h"

// ��������
int CreateLink(Link *h)
{
    unsigned int num;
    NodePtr ptr = new Node(); // ͷ���
    h->ptr = ptr;
    // ��������unsigned int ���͵���ֵ
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
    // ָ�������ÿ�
    for(int i=0;i<16;i++)
    {
        NodePtr p = new Node();
        h->Sort[i] = p;
        h->Sort[i]->next = NULL;
    }
    return 1;
}
