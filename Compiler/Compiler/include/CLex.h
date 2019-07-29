#ifndef CLEX_H
#define CLEX_H
#include "../Predefine.h"

class CLex
{
    public:
        CLex();
        ~CLex();
        int LexParse(std::string szSourceTxt);
        bool GenToken();                               // 生成单词流函数
        void SetKeyWords(std::string szStr,int ID);    // 设置关键字表函数
        void SetLexTbl(std::string szStr);             // 设置转换表函数
        void SetFileName(std::string szStr);           // 设置源程序文件名函数

    protected:

    private:
        /************** int LexTbl[50][130] ***************
         *  C语言中关键字，运算符，界符，标识符的字符
         *  都是ASCII码都小于128，而ASCII码大于127的字
         *  符只可能出现在字符串或者注释中，因此，所有
         *  的ASCII码大于127的字符在转换表中用一列表示
         *************************************************/
        int LexTbl[50][130];                // 转换表
        std::map<std::string,int> mKeyTbl;  // 关键字表，使用STL map
        std::string szSource;               // 源代码字符串
        std::string szFileName;             // 源程序文件名
        std::string szBuffer;               // 单词缓存区
        int iRow;                           // 当前行号
        int iNonTerminal;                   // 当前非终结状态编号
        int iPos;                           // 源代码当前读取位置指针
        std::vector<CToken>  pTokenList;    // 单词流
        bool Process(int iTag);             // 单词分析处理
        void EmitToken(const int iKind,const std::string szContent,const int iRow); // 记录单词函数
        void EmitToken(const int iKind,const int iRow);                             // 记录单词函数，重载函数，没有备注信息
        bool SearchKeyWord(std::string szKeyWord, int &iPosition);                  // 查询关键字表函数
        void BufferBack();                    // 单词缓存区回退函数
        int  ReadFile(std::string szStr);     // 读文件函数
        void EmitError(std::string szStr);    // 错误处理函数
        void SetKeyWords();                   // 设置关键字表函数
};

#endif // CLEX_H
