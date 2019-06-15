#include "Predefine.h"

// Êä³öÓÐÐòÐòÁÐ
int Print(Link *h)
{
    if(!h) return -1;
    NodePtr p = h->ptr->next;
    while(p)
    {
        std::cout << p->key << "  ";
        p = p->next;
    }
    std::cout << std::endl;
    return 1;
}
