#ifndef PREDEFINE_H_
#define PREDEFINE_H_
#include <iostream>
#include <cstdlib>

#define M 3 // mΪ4��B��
#define Min ((M-1)/2) // �ڵ���С�ؼ�����
typedef int KeyTp; // ����ؼ�������Ϊ��������

// B-���������Ͷ���
typedef struct node
{
    int n; // �ڵ��йؼ��ֵĸ���
    KeyTp K[M+1];  // �ؼ���������0��Ԫ��û��ʹ��
    struct node *A[M+1]; // ����ָ������
    struct node *parent; // ˫�׽ڵ�ָ��
}BSubTNode, *BSubT;

/* // �ڵ���ҷ���ֵ��������
 * typedef struct
 * {
 *     BSubT bt; // ���ҳɹ����سɹ��ڵ㣬ʧ�ܷ�����һ�β��ҵĽڵ�
 *     int i; // �ڵ�ָ��
 *     int flag; // ���ҽ����־����
 * }Result;
 */

#endif // PREDEFINE_H_
