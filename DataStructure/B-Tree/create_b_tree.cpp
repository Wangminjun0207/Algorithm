#include <fstream>
#include "Predefine.h"

extern BSubT BSubTInsert(BSubT t,int key);
//�����ļ�����b��
BSubT BSubTCreate()
{
	int key,i;
	BSubT t = new BSubTNode;//����ͷ��㲢��ʼ��
	t->parent = NULL;
	t->n = 0;
	for(i=0;i<=M;i++)
		t->A[i] = NULL;
	std::ifstream infile("input.txt");
	infile >> key;
	t->K[1] = key;
	t->n++;
	while(!infile.eof())
    {
		infile >> key;
		t = BSubTInsert(t,key);
	}
	std::cout << "Create Success!" << std::endl;
	infile.close();
	return t;
}
