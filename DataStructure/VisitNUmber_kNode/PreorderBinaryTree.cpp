#include "Predefine.h"

BiTree preorder(const BiTree bt, int &k)
{
	/**
	 * ����������ʵ� k���ڵ� 
	 * ����Ϊ������ͷ��㣬���ʵĽڵ�λ��
	 * ���ص� k ���ڵ�ָ�� 
	 */ 
	if(!bt)
	{
		return NULL;
	}
	k--;
	if(!k)
	{
		return bt;
	}
	BiTree p;
	p = preorder(bt->lelf_child,k);
	if(k==1)
	{
		p = preorder(bt->right_child,k);
	}
	return p;
}
