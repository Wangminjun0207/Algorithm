#include "Predefine.h"

// 访问节点函数
int Visit(ElemType e)
{
	std::cout << e << " ";
	return 1;
}
// 中序遍历
int Midorder(BSTree T)
{
	if(T)
	{
		if(Midorder(T->lchild))
			if(Visit(T->data))
				if(Midorder(T->rchild))
					return 1;
		return 0;
	}
	else
		return 1;
}
