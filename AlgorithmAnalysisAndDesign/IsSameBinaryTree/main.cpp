/*
 * �÷��η��ж������������Ƿ���ͬ
 */
#include <iostream>
#include <cstdio>
using namespace std;

typedef struct TreeNode{
	char data;
	TreeNode *leftchild;
	TreeNode *rightchild;
}TreeNode;
TreeNode * CreateBTree(){
	TreeNode * root = NULL;
	char temp;
	scanf("%c", &temp);
	if(temp != '#'){
		root = new TreeNode();
		root->data = temp;
		root->leftchild = CreateBTree();
		root->rightchild = CreateBTree();
		return root;
	}
	else{
		return NULL;
	}

}
void PrePrint(TreeNode *root){
	if (root != NULL){
		printf("%c", root->data);
		PrePrint(root->leftchild);
		PrePrint(root->rightchild);
	}
}
int cmpTree(TreeNode* tree1, TreeNode* tree2){
	//�п�
	bool isTree1Null = (tree1 == NULL);
	bool isTree2Null = (tree2 == NULL);
	//������һ�������գ���һ����Ϊ�գ���϶�����ȣ�����1
	if(isTree1Null != isTree2Null){
		return 1;
	}
	//��������Ϊ��
	if(isTree1Null && isTree2Null){
		return 0;
	}
	if(tree1->data != tree2->data){
		return 1;
	}
	//�жϺ����Ƿ����
	return (cmpTree(tree1->leftchild, tree2->leftchild) && cmpTree(tree1->rightchild, tree2->rightchild))
		|| (cmpTree(tree1->leftchild, tree2->rightchild) && cmpTree(tree1->rightchild, tree2->leftchild));
}

int main(){

	TreeNode *tree1 = CreateBTree();
	TreeNode *tree2 = CreateBTree();
	printf("%d", cmpTree(tree1, tree2));
	return 0;
}
