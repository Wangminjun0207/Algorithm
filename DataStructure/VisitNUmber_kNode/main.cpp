#include <iostream>
#include "Predefine.h" 
extern BiTree CrtBT();
extern void lasorder(const BiTree bt,int &k, BiTree &node);
extern void midorder(const BiTree bt,int &k, BiTree &node);
extern BiTree preorder(const BiTree bt, int &k);
int main(int argc, char** argv) 
{
	BiTree bt = CrtBT();
	int k1, k2, k3;
	std::cin >> k1;
	k2 = k3 = k1;
	BiTree node = new BiTreeNode();
	
	node = preorder(bt,k2);
	std::cout << "preorder:" <<  node->data << std::endl;
	
	midorder(bt,k1,node);
	std::cout << "midorder:" << node->data << std::endl;
	
	lasorder(bt,k3,node);
	std::cout << "lasorder:" <<  node->data << std::endl;
	
	return 0;
}
