#include "Predefine.h"

// 将链表节点数据按照升序连接
void LinkedSort(NodePtr h)
{
    // 链表为空
    if(h->next==NULL)
    {
        return;
    }

    // 使用选择排序
    for(NodePtr ptr=h->next;ptr!=NULL;ptr=ptr->next)
    {
        int min_val = ptr->key;
        NodePtr parent_ptr; // 内层排序真正的父节点指针
        for(NodePtr p=ptr->next;p!=NULL;p=p->next)
        {
            if(p->key<min_val)
            {
                min_val = p->key;
                parent_ptr = p;
            }
        }
        if(min_val!=ptr->key)
        {
            int temp = ptr->key;
            ptr->key = parent_ptr->key;
            parent_ptr->key = temp;
        }
    }
}
