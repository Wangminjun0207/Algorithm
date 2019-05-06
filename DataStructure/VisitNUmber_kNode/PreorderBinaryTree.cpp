#include "Predefine.h"

BiTree preorder(const BiTree bt, int &k)
{
	/**
	 * 后序遍历访问第 k个节点 
	 * 参数为二叉树头结点，访问的节点位置
	 * 返回第 k 个节点指针 
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
