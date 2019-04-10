/*
	Name:BinaryTreeHeight
	Copyright:
	Author:Wang minjun
	Date: 10/04/19 21:57
	Description:Calculate binary tree height.
*/
#include "Predefine.h"
extern BiTree CrtBT();
extern int TreeHeight(BiTree bt);
int main()
{
    BiTree bt = CrtBT();
    int height = TreeHeight(bt);
    std::cout << "tree height = " << height << std::endl;
    return 0;
}
