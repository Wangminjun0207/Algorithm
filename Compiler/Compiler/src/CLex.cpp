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
    bool bTag = true;   // �жϵ����Ƿ���ȷ�ı�־
    iPos = 0;           // Դ������ı��ĵ�ǰλ�ÿ�ʼ��ȡ
    ReadFile(szFileName); // ��ȡԴ�ļ�
    iNonTerminal = 0;
    szBuffer = "";
    iRow = 1;
    int TmpPos = 0; // ���������
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
            // ����ת��Ϊ�ַ�����
            char ptr[3];
            gcvt(iPos,2,ptr);
            EmitError(szFileName+"("+ptr+"lines"+"):�ʷ������������鵥��");
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
    int iPos = 0;             // ��ȡָ��
    bool bTag = true;         // ָʾ��ǰ�����Ƿ����
    int iState = 0;           // ��ʾ��ǰ״̬����ʼ����Ϊ0
    std::string szBuffer = "";// ���ʻ�����

    /*// ѭ����ȡԴ�����ı��ַ���ֱ��Դ�����β
    while(iPos<szSourceTxt.length() && bTag)
    {
        szBuffer = szBuffer + szSourceTxt.at(iPos);
        int iNextState = LexTbl[szSourceTxt.at(iPos)][iState];
        // ��ʾ��ǰ״̬�²������ȡ��ǰ�ַ�
        if(iNextState==-1)
        {
            bTag = false; //////////////////
        }
        else
        {
            // �ж��Ƿ���ֹ״̬
            if(!IsTerminal(iNextState))
            {
                iPos = iNextState; /////////////////
            }
            else
            {
                iPos--;                           // ���ڳ�ǰ����Ҫ��������λ��
                szBuffer.erase(szBuffer.end()-1); // �����ʻ���������һ���ַ�
                ProcessToken();
                szBuffer = "";
                iState = 0;
            }
        }
    }*/
    if(bTag==true) // �ʷ�����ʧ��
        return 1;
    else           // �ʷ������ɹ�
        return 0;
}

void CLex::EmitError(std::string szStr)
{
    std::cout << szStr << std::endl;
}

int CLex::ReadFile(std::string szStr)
{
    // ��ȡԴ����
    std::ifstream input;
    input.open(szStr.c_str());
    // �ļ���ʧ��
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
    szSource.push_back(' '); // �������һ�����ʵ�ʱ����ڳ�ǰ����
}

void CLex::BufferBack()
{
    szBuffer.erase(szBuffer.end()-1);
    iPos--;
}

bool CLex::Process(int iTag)
{

}
