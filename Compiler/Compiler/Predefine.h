#ifndef PREDEFINE_H
#define PREDEFINE_H

#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <cstdio>

// 单词行号信息数据结构
struct LineInfo
{
    int iRow;               // 单词所在行
    std::string szFileName; // 单词所在的源文件名
};


// 单词流数据结构
struct CToken
{
    int iKind;              // 单词的ID
    std::string szContent;  // 单词备注
    LineInfo mLineInfo;     // 单词行号信息
};

#endif // PREDEFINE_H
