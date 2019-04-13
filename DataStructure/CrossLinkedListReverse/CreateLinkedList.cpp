#include "Predefine.h"
// 用于从字符文件读入数据，并建立稀疏矩阵的十字链表结构
OLink init(FILE *file)
{
    OLink h = new OLNode;     // 建立总头结点
    // 从文件读入行、列、以及非零数据节点数
    fscanf(file,"%d%d%d",&h->i,&h->j,&h->data);

    // 以下建立行头节点数组
    OLink row = h->down = new OLNode[h->i];
    if(!row) return NULL;    // 返回NULL表示建立失败
    for(int i=0; i<h->i; i++)
    {
        // 位置为（i,-1)
        row[i].i = i;
        row[i].j = -1;
        row[i].right = &row[i]; // 建立循环链表
    }
    // 以下建立列头节点数组
    OLink col = h->right = new OLNode[h->j];
    if(!col) return NULL;   // 返回NULL表示建立失败
    for(int j=0;j<h->j;j++)
    {
        // 位置为(-1,j)
        col[j].i = -1;
        col[j].j = j;
        col[j].down = &col[j];  // 建立循环链表
    }
    return h;
}
