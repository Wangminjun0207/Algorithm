#include "Predefine.h"
// ����ڵ㵽ʮ������
int insert(OLink h, int i, int j, ElemTp data)
{
    int m = h->i;
    int n = h->j;
    if(i<0||i>=m||j<0||j>=n) return 0; // ��ʾ����ʧ��
    // �½�Ԫ�ؽڵ�
    OLink s = new OLNode;
    if(!s) return 0;
    s->i = i;
    s->j = j;
    s->data = data;
    // ���²����½ڵ�*s����i��ѭ������
    // �����ʹ��i��ѭ������ڵ㰴���±���������
    OLink pr = &h->down[i];
    OLink p = pr->right;
    while(p!=&h->down[i]&&j>p->j)
    {
        pr = p;
        p = p->right;
    }
    pr->right = s;
    s->right = p;
    // ���²����½ڵ�*s����j��ѭ������
    // �����ʹ��j��ѭ������ڵ㰴���±���������
    pr = &h->right[j];
    p = pr->down;
    while(p!=&h->right[j]&&i>p->i)
    {
        pr = p;
        p = p->down;
    }
    pr->down = s;
    s->down = p;
    return 1;
}
