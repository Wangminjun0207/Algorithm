#include "CLex.h"

CLex::CLex()
{
    //ctor
}

CLex::~CLex()
{
    //dtor
}

bool CLex::GenToken()
{
    bool bTag = true;   // 判断单词是否正确的标志
    iPos = 0;           // 源程序从文本的当前位置开始读取
    ReadFile(szFileName); // 读取源文件
    iNonTerminal = 0;
    szBuffer = "";
    iRow = 1;
    int TmpPos = 0; // 单词流清空
    pTokenList.clear();
    while(iPos<szSource.length() && bTag)
    {
        if(szSource[iPos]=='\n' && TmpPos!=iPos)
        {
            iRow++;
            TmpPos = iPos;
        }
        szBuffer.push_back(szSource.at(iPos));
        bTag = Process(LexTbl[iNonTerminal][szSource[iPos]<128?szSource[iPos]:128]);
        if(!bTag)
        {
            // 整数转换为字符类型
            char ptr[3];
            gcvt(iPos,2,ptr);
            EmitError(szFileName+"("+ptr+"lines"+"):词法分析错误，请检查单词");
            return false;
        }
        iPos++;
    }
    std::cout << iRow << "hhh";
    return bTag;
}

void CLex::SetKeyWords(std::string szStr,int ID)
{
    mKeyTbl.insert(std::pair<std::string, int>(szStr,ID));
}

void CLex::SetKeyWords()
{
    mKeyTbl.insert(std::pair<std::string, int>("vv",1));
}

void CLex::SetLexTbl(std::string szStr)
{

}

void CLex::SetFileName(std::string szStr)
{
    szFileName += szStr;
}

int CLex::LexParse(std::string szSourceTxt)
{
    int iPos = 0;             // 读取指针
    bool bTag = true;         // 指示当前单词是否出错
    int iState = 0;           // 表示当前状态，初始设置为0
    std::string szBuffer = "";// 单词缓冲区

    /*// 循环读取源程序文本字符，直至源程序结尾
    while(iPos<szSourceTxt.length() && bTag)
    {
        szBuffer = szBuffer + szSourceTxt.at(iPos);
        int iNextState = LexTbl[szSourceTxt.at(iPos)][iState];
        // 表示当前状态下不允许读取当前字符
        if(iNextState==-1)
        {
            bTag = false; //////////////////
        }
        else
        {
            // 判断是否到终止状态
            if(!IsTerminal(iNextState))
            {
                iPos = iNextState; /////////////////
            }
            else
            {
                iPos--;                           // 由于超前搜索要回退搜索位置
                szBuffer.erase(szBuffer.end()-1); // 将单词缓存区回退一个字符
                ProcessToken();
                szBuffer = "";
                iState = 0;
            }
        }
    }*/
    if(bTag==true) // 词法分析失败
        return 1;
    else           // 词法分析成功
        return 0;
}

void CLex::EmitError(std::string szStr)
{
    std::cout << szStr << std::endl;
}

int CLex::ReadFile(std::string szStr)
{
    // 读取源代码
    std::ifstream input;
    input.open(szStr.c_str());
    // 文件打开失败
    if(!input.is_open())
    {
        std::cout << "Error opening file";
        return 0;
    }
    while (!input.eof())
    {
        std::string strTemp;
        input >> strTemp;
        strTemp += " ";
        szSource += strTemp;
    }
    input.close();
    std::cout << szSource << std::endl;
    szSource.push_back(' '); // 处理最后一个单词的时候便于超前搜索
}

void CLex::BufferBack()
{
    szBuffer.erase(szBuffer.end()-1);
    iPos--;
}

bool CLex::Process(int iTag)
{

}
