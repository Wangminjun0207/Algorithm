#include "Predefine.h"

void midorder(const BiTree bt, int &k, BiTree &node)
{
	/**
	 * ����������ʵ� k���ڵ� 
	 * ����Ϊ������ͷ��㣬���ʵĽڵ�λ�ã��ڵ�ָ������� 
	 */ 
	if(!bt || !k)
	{
		return;
	}
	midorder(bt->lelf_child,k,node);
    if(k>0)
    {
        k--;
        if(k==0)
        {
        	node = bt;
        	return;
		}
		midorder(bt->right_child,k,node);
    }
}
