#include "Predefine.h"
extern OLink delNode(OLink h);
extern int insert_RevMatrix(OLink row, OLink col, OLink s);
// 十字链表存储的稀疏矩阵转置
OLink reverse(OLink h)
{
    // 以下建立行头节点数组
    OLink row = new OLNode[h->j];//转置之后行数等于原来的列数
    if(!row) return NULL;        // 返回NULL表示建立失败
    for(int i=0; i<h->j; i++)
    {
        // 位置为（i,-1)
        row[i].i = i;
        row[i].j = -1;
        row[i].right = &row[i]; // 建立循环链表
    }
    // 以下建立列头节点数组
    OLink col = new OLNode[h->i];//转置之后列数等于原来的行数
    if(!col) return NULL;       // 返回NULL表示建立失败
    for(int j=0;j<h->i;j++)
    {
        // 位置为(-1,j)
        col[j].i = -1;
        col[j].j = j;
        col[j].down = &col[j];  // 建立循环链表
    }
    int count = h->data; // 存储矩阵中元素非零的个数
    OLink s;
    int temp;
    while(count)
    {
        s = delNode(h);
        // 行列顺序互相交换
        temp = s->i;
        s->i = s->j;
        s->j = temp;;
        insert_RevMatrix(row, col, s);// 在转置链表中插入s节点
        --count;
    }
    // 行列顺序互相交换
    temp = h->i;
    h->i = h->j;
    h->j = temp;
    delete []h->down;      // 释放原来矩阵的行数组
    delete []h->right;     // 释放原来矩阵的列数组
    h->down = row;         // 总头结点down指向新矩阵的行数组
    h->right = col;        // 总头结点right指向新矩阵的列数组
    return h;
}
