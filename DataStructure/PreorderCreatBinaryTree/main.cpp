/*
	Name:PreorderCreateBinaryTree
	Copyright:
	Author:Wang minjun
	Date: 10/04/19 21:05
	Description:use previous order create and visit binary tree.
*/
#include "Predefine.h"
extern BiTree CrtBT();
extern void preorder(const BiTree bt);
extern void midorder(const BiTree bt);
extern void lasorder(const BiTree bt);
int main()
{
    BiTree bt = CrtBT();
    preorder(bt);
	midorder(bt);
	lasorder(bt);
    return 0;
}
