#include "Predefine.h"

// ��ת��ʮ�������в���ڵ�
int insert_RevMatrix(OLink row, OLink col, OLink s)
{
    // ���²����½ڵ�*s����i��ѭ������
    // �����ʹ��i��ѭ������ڵ㰴���±���������
    OLink pr = &row[s->i];
    OLink p = pr->right;
    while(p!=&row[s->i]&&s->j>p->j)
    {
        pr = p;
        p = p->right;
    }
    pr->right = s;
    s->right = p;
    // ���²����½ڵ�*s����j��ѭ������
    // �����ʹ��j��ѭ������ڵ㰴���±���������
    pr = &col[s->j];
    p = pr->down;
    while(p!=&col[s->j]&&s->i>p->i)
    {
        pr = p;
        p = p->down;
    }
    pr->down = s;
    s->down = p;
    return 1;
}
