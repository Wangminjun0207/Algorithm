#ifndef PREDEFINE_H_
#define PREDEFINE_H_
#include <iostream>
#include <cstdlib>

#define M 3 // m为4的B树
#define Min ((M-1)/2) // 节点最小关键字数
typedef int KeyTp; // 定义关键字类型为整数类型

// B-树数据类型定义
typedef struct node
{
    int n; // 节点中关键字的个数
    KeyTp K[M+1];  // 关键字向量，0号元素没有使用
    struct node *A[M+1]; // 子树指针向量
    struct node *parent; // 双亲节点指针
}BSubTNode, *BSubT;

/* // 节点查找返回值数据类型
 * typedef struct
 * {
 *     BSubT bt; // 查找成功返回成功节点，失败返回上一次查找的节点
 *     int i; // 节点指针
 *     int flag; // 查找结果标志变量
 * }Result;
 */

#endif // PREDEFINE_H_
