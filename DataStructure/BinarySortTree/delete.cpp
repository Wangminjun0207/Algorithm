#include "Predefine.h"
extern BST Search(BST bt, int k);

// ����������ɾ���ڵ���㷨
int Delete(BST bt, int k)
{
    BST p = Search(bt,k);
    if(p==NULL)
    {
        std::cout << "don't find!" << std::endl;
        return 0; // �ڵ㲻���ڣ�ɾ��ʧ��
    }
    BST temp = NULL;
    // ��ɾ�ڵ���Ҷ�ӽڵ�
    if(!(p->lchild && p->rchild))
    {
        temp = p;
        p = NULL;
        free(temp);
    }
    // ��ɾ�ڵ����Ҷ��Ӷ�����
    else if(p->lchild && p->rchild)
    {
        BST r_node = p->rchild;
        temp = p;
        p = p->lchild; // �������˫�׽ڵ�����
        // ��*p������������������ʵĽڵ�ָ��s
        BST s = p;
        while(s->rchild)
        {
            s = s->rchild;
        }
        s->rchild = r_node;
        free(temp);
    }
    // ��ɾ�ڵ�ֻ����һ������
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
