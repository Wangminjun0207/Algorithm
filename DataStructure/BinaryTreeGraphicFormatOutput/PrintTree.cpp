#include "Predefine.h"
extern int g_nCount;
extern std::vector<ElemTp> List;

// �������������������
void printTree(std::vector<ElemTp> tree)
{
    int tree_size = tree.size();// ���Ľڵ���Ŀ
    if(!tree_size)
    {
        exit(0);
    }
    int size_format[4] = {40,30,25,22};  // ÿһ�е���ʼλ��
    int size_space[4] = {40,20,10,4};    // ����"|"֮��Ŀո���
    std::string symbol[4] = {"____________________","__________","_____","___"}; // ������״���Ʒ�
    int size_interval[4] = {20,10,5,3};   // ÿ���ڵ����֦�ľ���
    int layer_number = log(tree_size+1)/log(2); // ��¼���Ĳ���
    std::cout << std::setw(61) << List.at(0) << std::endl;// �����һ��
    int number = 1; // ��¼�Ѿ������ʵĽڵ���
    int *dp = new int[128];
    // std::cout << layer_number <<std::endl;
    for(int i=2;i<layer_number;i++)
    {
        // ������Ľӽڵ�λ����Ϣ
        for(int j=1;j<=pow(2,i-1);j++)
        {
            if(List.at(number)!='#')
            {
                dp[j-1] = 1;
            }
            else{
                dp[j-1] = 0;
            }
            number++;
        }

        // �������������֦����
        std::cout << std::setw(size_format[i-2])<<' ';
        for(int k=1;k<=pow(2,i-1);k += 2)
        {
            // �ϸ��ڵ����������ӵĸ�ʽ
            if(dp[k-1] && dp[k])
            {
                std::cout << symbol[i-2]+"|"+symbol[i-2];
                std::cout << std::setw(size_space[i-2]-1) << " ";
                continue;
            }
            // �ϸ��ڵ�������ӵĸ���
            else if(dp[k-1])
            {
                std::cout << symbol[i-2]+"|";
                std::cout << std::setw(size_interval[i-2]-1) << " ";
                std::cout << std::setw(size_space[i-2]) << " ";
                continue;
            }
            // �ϸ��ڵ����Ҷ��ӵĸ�ʽ
            else if(dp[k])
            {
                std::cout << std::setw(size_interval[i-2]) << " ";
                std::cout << "|"+symbol[i-2];
                std::cout << std::setw(size_space[i-2]-1) << " ";
                continue;
            }
            // �ϸ��ڵ�û���ӵĸ�ʽ
            else{
                std::cout << std::setw(size_interval[i-2]*2) << " ";
                std::cout << std::setw(size_space[i-2]-1) << " ";
            }
        }
        std::cout << std::endl; // ���һ�����з���֮���껻����һ��

        /***************************************************************
          ���µ�ѭ������Ϊ�˿��ƶ������ĸ�ʽ������ע��������ѭ������
         **************************************************************/

        // ����������ڵ㶥����"|"����
        std::cout << std::setw(size_format[i-2])<<' ';
        for(int j=1;j<=pow(2,i-1);j+=2)
        {
            if(dp[j-1] && dp[j])
            {
                std::cout << "|";
                std::cout << std::setw(size_interval[i-2]*2-1) << " ";
                std::cout << "|";
                std::cout << std::setw(size_space[i-2]-1) << " ";
                continue;
            }
            else if(dp[j-1])
            {
                std::cout << "|";
                std::cout << std::setw(size_interval[i-2]*2-1) << " ";
                std::cout << std::setw(size_space[i-2]-1) << " ";
                continue;
            }
            else if(dp[j])
            {
                std::cout << std::setw(size_interval[i-2]*2) << " ";
                std::cout << "|";
                std::cout << std::setw(size_space[i-2]-1) << " ";
                continue;
            }
            else{
                std::cout << std::setw(size_interval[i-2]*2-1) << " ";
                std::cout << std::setw(size_space[i-2]) << " ";
            }
        }
        std::cout << std::endl;

        // ����������ڵ�
        int temp = number - pow(2,i-1);
        std::cout << std::setw(size_format[i-2])<<' ';
        for(int j=1;j<=pow(2,i-1);j+=2)
        {
            if(dp[j-1] && dp[j])
            {
                std::cout << List.at(temp++);
                std::cout << std::setw(size_interval[i-2]*2-1) << " ";
                std::cout << List.at(temp++);
                std::cout << std::setw(size_space[i-2]-1) << " ";
                continue;
            }
            else if(dp[j-1])
            {
                std::cout << List.at(temp++);
                std::cout << std::setw(size_interval[i-2]*2-1) << " ";
                std::cout << std::setw(size_space[i-2]-1) << " ";
                temp++;
                continue;
            }
            else if(dp[j])
            {
                temp++;
                std::cout << std::setw(size_interval[i-2]*2) << " ";
                std::cout << List.at(temp++);
                std::cout << std::setw(size_space[i-2]-1) << " ";
                continue;
            }
            else{
                std::cout << std::setw(size_interval[i-2]*2-1) << " ";
                std::cout << std::setw(size_space[i-2]) << " ";
                temp += 2;
            }
        }
        std::cout << std::endl;
    }
    delete []dp;
}
