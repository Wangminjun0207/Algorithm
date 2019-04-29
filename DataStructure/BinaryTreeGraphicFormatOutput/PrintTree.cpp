#include "Predefine.h"
extern std::vector<ElemTp> List;

// 将二叉树按照树形输出
void printTree(std::vector<ElemTp> tree)
{
    int tree_size = tree.size();// 树的节点数目
    if(!tree_size)
    {
        exit(0);
    }
    int size_format[5] = {40,30,25,22,21};  // 每一行的起始位置
    int size_space[5] = {40,20,10,4,3};     // 两个"|"之间的空格数
    std::string symbol[5] = {"____________________","__________","_____","___","_"}; // 树的形状控制符
    int size_interval[5] = {20,10,5,3,1};   // 每个节点横向枝的距离
    int layer_number = log(tree_size+1)/log(2); // 记录树的层数
    std::cout << std::setw(61) << List.at(0) << std::endl;// 输出第一层
    int number = 1; // 记录已经被访问的节点数
    int *dp = new int[32];
    // std::cout << layer_number <<std::endl;
    for(int i=2;i<layer_number;i++)
    {
        // 求出树的接节点位置信息
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

        // 输出二叉树的树枝符号
        std::cout << std::setw(size_format[i-2])<<' ';
        for(int k=1;k<=pow(2,i-1);k += 2)
        {
            // 上个节点有两个儿子的格式
            if(dp[k-1] && dp[k])
            {
                std::cout << symbol[i-2]+"|"+symbol[i-2];
                std::cout << std::setw(size_space[i-2]-1) << " ";
                continue;
            }
            // 上个节点有左儿子的个数
            else if(dp[k-1])
            {
                std::cout << symbol[i-2]+"|";
                std::cout << std::setw(size_interval[i-2]-1) << " ";
                std::cout << std::setw(size_space[i-2]) << " ";
                continue;
            }
            // 上个节点有右儿子的格式
            else if(dp[k])
            {
                std::cout << std::setw(size_interval[i-2]) << " ";
                std::cout << "|"+symbol[i-2];
                std::cout << std::setw(size_space[i-2]-1) << " ";
                continue;
            }
            // 上个节点没儿子的格式
            else{
                std::cout << std::setw(size_interval[i-2]*2) << " ";
                std::cout << std::setw(size_space[i-2]-1) << " ";
            }
        }
        std::cout << std::endl; // 输出一行所有符号之后光标换到下一行

        /***************************************************************
          以下的循环都是为了控制二叉树的格式，代码注释与上面循环类似
         **************************************************************/

        // 输出二叉树节点顶部的"|"符号
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

        // 输出二叉树节点
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
