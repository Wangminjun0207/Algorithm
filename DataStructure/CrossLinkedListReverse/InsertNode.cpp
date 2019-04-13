#include "Predefine.h"
// 插入节点到十字链表
int insert(OLink h, int i, int j, ElemTp data)
{
    int m = h->i;
    int n = h->j;
    if(i<0||i>=m||j<0||j>=n) return 0; // 表示插入失败
    // 新建元素节点
    OLink s = new OLNode;
    if(!s) return 0;
    s->i = i;
    s->j = j;
    s->data = data;
    // 以下插入新节点*s到第i行循环链表
    // 插入后使第i行循环链表节点按照下标升序连接
    OLink pr = &h->down[i];
    OLink p = pr->right;
    while(p!=&h->down[i]&&j>p->j)
    {
        pr = p;
        p = p->right;
    }
    pr->right = s;
    s->right = p;
    // 以下插入新节点*s到第j列循环链表
    // 插入后使第j列循环链表节点按照下标升序连接
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
