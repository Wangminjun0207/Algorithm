/* Name:TestCodeBlockss
 * Copyright:null
 * Author:Wang Minjun
 * Date: 11/03/19 11:20
 * Description:�Ӽ����������ݣ�����������ͷ���ĵ�������
 *             ���ڵ����Ӵ���������ݽڵ�����ݣ�
 *             ʵ�����ݽڵ㰴�ڵ����ݴ�С����Ĵ������ӣ�
 *             ���ڵ����Ӵ�����������Ľڵ����ݣ�
 *             ʵ�����ݽڵ��������ӣ�
 *             ���ڵ����Ӵ�������������Ӻ�����ݽڵ�����ݣ�
 */

#include <stdio.h>
#include <stdlib.h>
#include "predefine.h"

/* �ڴ˴����Ե�ʱ����������:C�����ļ�����ĺ�����
 * C++�ļ�����extern������ʱ����ִ���ͨ��ĳ�ȵ�
 * ��ѯ��֪�Ǳ���������C���Ժ�c++��������ʱ��������
 *һ���� ���Ե��³��ִ���
 */
extern void display(NodePtr h);
extern NodePtr create();
extern void reverse(NodePtr h);
extern void sort(NodePtr h);

int main()
{
    NodePtr h;
    printf("�������ɷ���������ֱ��������ʱֹͣ��������������");
    h = create();
    printf("ԭ���Ӵ���");
    display(h);
    printf("\n");
    sort(h);
    printf("��������");
    display(h);
    printf("\n");
    reverse(h);
    printf("��������");
    display(h);
    printf("\n");
    return 0;
}
