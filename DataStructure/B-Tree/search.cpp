#include <vector>
#include "Predefine.h"
extern int Search(BSubT p, KeyTp key);
extern std::vector<int> infor;

// B-�����ҽڵ��㷨
void BSubTSearch(BSubT t, KeyTp key)
{
    BSubT p = t;
    bool found = false;
    int it = 0; // �ڵ�ָ��
    infor.clear(); // ���֮ǰ������
    while(p && !found)
    {
        it = Search(p,key);
        // �ҵ��ڵ�
        if(it>0 && p->K[it]==key)
        {
            found = true;
            break;
        }
        // û���ҵ��ڵ�
        else{
            p = p->A[it];
            infor.push_back(it);
        }
    }
    if(found)
    {

        std::cout<<"(R";
		for(int i=0;i<int(infor.size());i++)
        {
            std::cout << infor[i];
        }
		std::cout<<","<<p->n<<",";
		for(int i=1;i<=p->n;i++)
			std::cout<<p->K[i]<<" ";
		std::cout<<")"<<std::endl;
    }
    else{
        std::cout << "search failed!" << std::endl;
    }
}

// �ڵ��ڲ���key,���㷵���±�
int Search(BSubT p, KeyTp key)
{
    int it_;
    for(it_=1;it_<=p->n;it_++)
    {
        if(p->K[it_]>key)
        {
            break;
        }
    }
    return it_-1;
}
