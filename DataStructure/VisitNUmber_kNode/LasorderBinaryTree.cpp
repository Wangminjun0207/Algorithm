#include "Predefine.h"

void lasorder(const BiTree bt,int &k,BiTree &node)
{
	/**
	 * 后序遍历访问第 k个节点 
	 * 参数为二叉树头结点，访问的节点位置，节点指针的引用 
	 */ 
    if(!bt || !k)
    {
    	return;
    }
    lasorder(bt->lelf_child,k,node);
    lasorder(bt->right_child,k,node);
	k--;
    if(k==0)
    {
    	node = bt;
    	return;
	}
}
