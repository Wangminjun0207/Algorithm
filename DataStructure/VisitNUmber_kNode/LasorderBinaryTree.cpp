#include "Predefine.h"

void lasorder(const BiTree bt,int &k,BiTree &node)
{
	/**
	 * ����������ʵ� k���ڵ� 
	 * ����Ϊ������ͷ��㣬���ʵĽڵ�λ�ã��ڵ�ָ������� 
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
