#include "Predefine.h"
extern std::vector<BST> Search(BST bt, int k);

// ���Ӹ��ڵ��Ҫɾ���ڵ�ĺ���
void Connect(std::vector<BST> result, BST temp, BST bt)
{
    // ��ɾ�ڵ��Ǹ��ڵ����
    if(result.at(1)==NULL)
    {
        result.at(1) = temp;
        return;
    }
    // ��ɾ�ڵ��������
    if(temp==result.at(1)->lchild)
    {
        result.at(1)->lchild = bt;
    }
    // ��ɾ�ڵ����Ҷ���
    else{
        result.at(1)->rchild = bt;
    }
}

// ����������ɾ���ڵ���㷨
int Delete(BST bt, int k)
{
    std::vector<BST> result = Search(bt,k);
    if(result.at(0)==NULL)
    {
        std::cout << "don't find!" << std::endl;
        return 0; // �ڵ㲻���ڣ�ɾ��ʧ��
    }
    BST temp = NULL;
    BST p = result.at(0);

    // ��ɾ�ڵ���Ҷ�ӽڵ�
    if(!(p->lchild && p->rchild))
    {
        temp = p;
        p = NULL;
        Connect(result,temp,p);
        free(temp);
    }
    // ��ɾ�ڵ����Ҷ��Ӷ�����
    else if(p->lchild && p->rchild)
    {
        BST r_node = p->rchild;
        temp = p;
        p = p->lchild; // �������˫�׽ڵ�����
        Connect(result,temp,p);
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
