#ifndef PREDEFINE_H_
#define PREDEFINE_H_
#include <iostream>
#include <cstdlib>

// �ڵ����ݽṹ
typedef struct node
{
    unsigned int key;
    struct node *next;
}Node, *NodePtr;

// �����������ݽṹ
typedef struct link
{
    NodePtr ptr;
    NodePtr Sort[16];
}Link;

#endif // PREDEFINE_H_
