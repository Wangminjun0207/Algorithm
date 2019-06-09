#include "Predefine.h"
#include <iostream>
#include <queue>
#include <vector>
#include <iomanip>
#include <fstream>

// 输出到文件的节点信息数据类型
typedef struct output
{
    BSubT bt;
    std::vector<int> infor;
}Output;


// 层次遍历输出B-树的所有节点信息
void Layorder(BSubT bt)
{
    std::queue<Output> Queue;
    Output temp;
    Output t;
    std::vector<int> list_;
    int n; // 记录节点数据个数

    // 根节点不空，入栈
    if(bt)
    {
        temp.bt = bt;
        temp.infor = list_;
        Queue.push(temp);
    }
    std::ofstream file;
    file.open("output.txt");
    while(!Queue.empty())
    {
        temp = Queue.front();
        Queue.pop();
        // 访问数据域
        file<<"(R";
		for(int i=0;i<temp.infor.size();i++)
			file<<temp.infor[i];
		file<<","<<temp.bt->n<<",";
        for(n=1;n<=temp.bt->n;n++)
        {
            file << temp.bt->K[n] << " ";
        }
        file<<")"<<std::endl;
        // 非空节点入栈

        for(n=0;n<=temp.bt->n;n++)
        {
            list_ = temp.infor;
            list_.push_back(n);
            if(temp.bt->A[n]!=NULL)
            {
                t.bt = temp.bt->A[n];
                t.infor = list_;
                Queue.push(t);
            }
        }
    }
    std::cout << "The traversal result has been written to the file!" << std::endl;
}
