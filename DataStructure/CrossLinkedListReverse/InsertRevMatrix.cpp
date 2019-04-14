#include "Predefine.h"

// 在转置十字链表中插入节点
int insert_RevMatrix(OLink row, OLink col, OLink s)
{
    // 以下插入新节点*s到第i行循环链表
    // 插入后使第i行循环链表节点按照下标升序连接
    OLink pr = &row[s->i];
    OLink p = pr->right;
    while(p!=&row[s->i]&&s->j>p->j)
    {
        pr = p;
        p = p->right;
    }
    pr->right = s;
    s->right = p;
    // 以下插入新节点*s到第j列循环链表
    // 插入后使第j列循环链表节点按照下标升序连接
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
