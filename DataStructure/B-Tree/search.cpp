#include <vector>
#include "Predefine.h"
extern int Search(BSubT p, KeyTp key);
extern std::vector<int> infor;

// B-树查找节点算法
void BSubTSearch(BSubT t, KeyTp key)
{
    BSubT p = t;
    bool found = false;
    int it = 0; // 节点指针
    infor.clear(); // 清除之前的数据
    while(p && !found)
    {
        it = Search(p,key);
        // 找到节点
        if(it>0 && p->K[it]==key)
        {
            found = true;
            break;
        }
        // 没有找到节点
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

// 节点内查找key,满足返回下标
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
