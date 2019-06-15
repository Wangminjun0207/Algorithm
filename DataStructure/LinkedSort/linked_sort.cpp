#include "Predefine.h"

// ������ڵ����ݰ�����������
void LinkedSort(NodePtr h)
{
    // ����Ϊ��
    if(h->next==NULL)
    {
        return;
    }

    // ʹ��ѡ������
    for(NodePtr ptr=h->next;ptr!=NULL;ptr=ptr->next)
    {
        int min_val = ptr->key;
        NodePtr parent_ptr; // �ڲ����������ĸ��ڵ�ָ��
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
