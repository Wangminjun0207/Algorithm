#ifndef TRAVEL_H
#define TRAVEL_H
#include <iostream>
#include <iomanip>

#define MAX_N 20 // ���ڵ���Ŀ
class Travel
{
    public:
        Travel();
        virtual ~Travel();
        int InitGraph(); // ��ʼ��ͼ
        int DFSTravel(); // �����������
        int BFSTravel(); // �����������
        int FirstAdj(int i);  // ���ؽڵ�i�ĵ�һ���ڽӽڵ�
        int NextAdj(int i, int j); // ���ؽڵ�i�Ĺ��ڽڵ�j����һ���ڵ�
        friend void DFS(Travel t, bool visited[], int i);
    protected:

    private:
        int node_count_; // �ڵ���Ŀ
        int arcs[MAX_N][MAX_N]; // �ڽӾ���
};



#endif // TRAVEL_H
