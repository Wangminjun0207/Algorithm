/**
  * ��������n���޷�������������ʽ��������ʵ����С����
  * �����������������ʾ������C����32bit���unsigned���ͣ�
  * ���Բ���16������ʽ��ʵ�ֻ������򣬼�32bit����8��16����λ��
  * ÿ��16����λ����һ�˷�����ռ�����8�ˡ�
  */


#include <iostream>
#include "Predefine.h"
extern int CardinalSort(Link *h);
extern int CreateLink(Link *h);
extern int Print(Link *h);

int main()
{
    Link *h = new Link();
    CreateLink(h);
    Print(h);
    CardinalSort(h);
    Print(h);
    return 0;
}
