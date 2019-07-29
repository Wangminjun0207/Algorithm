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

// �����к���Ϣ���ݽṹ
struct LineInfo
{
    int iRow;               // ����������
    std::string szFileName; // �������ڵ�Դ�ļ���
};


// ���������ݽṹ
struct CToken
{
    int iKind;              // ���ʵ�ID
    std::string szContent;  // ���ʱ�ע
    LineInfo mLineInfo;     // �����к���Ϣ
};

#endif // PREDEFINE_H
