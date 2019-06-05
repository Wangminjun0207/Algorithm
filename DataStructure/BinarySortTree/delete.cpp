#include "Predefine.h"
extern BST Search(BST bt, int k);

// 二叉排序树删除节点的算法
int Delete(BST bt, int k)
{
    BST p = Search(bt,k);
    if(p==NULL)
    {
        std::cout << "don't find!" << std::endl;
        return 0; // 节点不存在，删除失败
    }
    BST temp = NULL;
    // 被删节点是叶子节点
    if(!(p->lchild && p->rchild))
    {
        temp = p;
        p = NULL;
        free(temp);
    }
    // 被删节点左右儿子都存在
    else if(p->lchild && p->rchild)
    {
        BST r_node = p->rchild;
        temp = p;
        p = p->lchild; // 左儿子与双亲节点连接
        // 求*p左子树中序遍历最后访问的节点指针s
        BST s = p;
        while(s->rchild)
        {
            s = s->rchild;
        }
        s->rchild = r_node;
        free(temp);
    }
    // 被删节点只存在一个儿子
    else{
        temp = p;
        if(p->lchild)
        {
            p = p->lchild;
        }
        else{
            p = p->rchild;
        }
        free(temp);
    }
}
