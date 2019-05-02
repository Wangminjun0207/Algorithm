#include "Predefine.h"
BiT createBiTree(char *preorder, char *midorder, int *i, int first, int last)
{
	/** 使用先序遍历序列和后续遍历序列建立二叉树
	  * char *preorder 先序遍历序列
	  * char *midorder 中序遍历序列
	  * int *i preorder迭代器
	  * int first 中序遍历序列起始位置
	  * int last 中序遍历序列末端位置
	  */
	 BiT bt;
	 int it;
	 if(first>last)
	 {
		 return NULL;
	 }
	 bt = (BiT)malloc(sizeof(BiTree));
	 bt->data = preorder[*i];
	 *i += 1;
	 for(it=first;it<=last;it++)
	 {
		 if(midorder[it]==bt->data)
		 {
			 break;
		 }
	 }
	 // 递归建立左儿子和右儿子
	 bt->left_child = createBiTree(preorder,midorder,i,first,it-1);
	 bt->right_child = createBiTree(preorder,midorder,i,it+1,last);
	 return bt;
}
