#include "Predefine.h"
extern std::vector<BST> Search(BST bt, int k);

// 连接父节点和要删除节点的孩子
void Connect(std::vector<BST> result, BST temp, BST bt)
{
    // 被删节点是根节点情况
    if(result.at(1)==NULL)
    {
        result.at(1) = temp;
        return;
    }
    // 被删节点是左儿子
    if(temp==result.at(1)->lchild)
    {
        result.at(1)->lchild = bt;
    }
    // 被删节点是右儿子
    else{
        result.at(1)->rchild = bt;
    }
}

// 二叉排序树删除节点的算法
int Delete(BST bt, int k)
{
    std::vector<BST> result = Search(bt,k);
    if(result.at(0)==NULL)
    {
        std::cout << "don't find!" << std::endl;
        return 0; // 节点不存在，删除失败
    }
    BST temp = NULL;
    BST p = result.at(0);

    // 被删节点是叶子节点
    if(!(p->lchild && p->rchild))
    {
        temp = p;
        p = NULL;
        Connect(result,temp,p);
        free(temp);
    }
    // 被删节点左右儿子都存在
    else if(p->lchild && p->rchild)
    {
        BST r_node = p->rchild;
        temp = p;
        p = p->lchild; // 左儿子与双亲节点连接
        Connect(result,temp,p);
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
            Connect(result,temp,p);
        }
        else{
            p = p->rchild;
            Connect(result,temp,p);
        }
        free(temp);
    }
    return 1;
}
