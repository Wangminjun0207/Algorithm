#ifndef PREDEFINE_H_
#define PREDEFINE_H_
#include <cstdlib>
#include <iostream>

#define EQ(a,b) ((a)==(b))
#define LT(a,b) ((a)<(b))
#define LQ(a,b) ((a)<=(b))
#define LH 1
#define EH 0
#define RH -1

typedef int ElemType;
//ƽ��������ṹ
typedef struct BSTNode
{
        ElemType data;
        int bf;
        struct BSTNode *lchild,*rchild;
}BSTNode,*BSTree;

#endif // PREDEFINE_H_
