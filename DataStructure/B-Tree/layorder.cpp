#include "Predefine.h"
#include <iostream>
#include <queue>
#include <vector>
#include <iomanip>
#include <fstream>

// ������ļ��Ľڵ���Ϣ��������
typedef struct output
{
    BSubT bt;
    std::vector<int> infor;
}Output;


// ��α������B-�������нڵ���Ϣ
void Layorder(BSubT bt)
{
    std::queue<Output> Queue;
    Output temp;
    Output t;
    std::vector<int> list_;
    int n; // ��¼�ڵ����ݸ���

    // ���ڵ㲻�գ���ջ
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
        // ����������
        file<<"(R";
		for(int i=0;i<temp.infor.size();i++)
			file<<temp.infor[i];
		file<<","<<temp.bt->n<<",";
        for(n=1;n<=temp.bt->n;n++)
        {
            file << temp.bt->K[n] << " ";
        }
        file<<")"<<std::endl;
        // �ǿսڵ���ջ

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
