#ifndef PREDEFINE_H_
#define PREDEFINE_H_
#include <stdio.h>
#include <stdlib.h>

typedef char ElemTp;
typedef struct BinaryTree
{
	ElemTp data; // 节点数据域
	struct BinaryTree *left_child; // 左儿子指针
	struct BinaryTree *right_child; // 右儿子指针
}*BiT,BiTree;
#endif
