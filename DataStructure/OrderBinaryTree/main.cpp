/*
	Name:PreorderCreateBinaryTree
	Copyright:
	Author:Wang minjun
	Date: 22/04/19 11:05
	Description:use previous order create and visit binary tree.
*/
#include "Predefine.h"
extern BiTree CrtBT();
extern void preorder(const BiTree bt);
extern void midorder(const BiTree bt);
extern void lasorder(const BiTree bt);
extern int LayerTraval(BiTree bt);
int main()
{
    BiTree bt = CrtBT();
    preorder(bt);
    std::cout << std::endl;
	midorder(bt);
	std::cout << std::endl;
	lasorder(bt);
	std::cout << std::endl;
	LayerTraval(bt);
    return 0;
}
