#ifndef CLEX_H
#define CLEX_H
#include "../Predefine.h"

class CLex
{
    public:
        CLex();
        ~CLex();
        int LexParse(std::string szSourceTxt);
        bool GenToken();                               // ���ɵ���������
        void SetKeyWords(std::string szStr,int ID);    // ���ùؼ��ֱ���
        void SetLexTbl(std::string szStr);             // ����ת������
        void SetFileName(std::string szStr);           // ����Դ�����ļ�������

    protected:

    private:
        /************** int LexTbl[50][130] ***************
         *  C�����йؼ��֣���������������ʶ�����ַ�
         *  ����ASCII�붼С��128����ASCII�����127����
         *  ��ֻ���ܳ������ַ�������ע���У���ˣ�����
         *  ��ASCII�����127���ַ���ת��������һ�б�ʾ
         *************************************************/
        int LexTbl[50][130];                // ת����
        std::map<std::string,int> mKeyTbl;  // �ؼ��ֱ�ʹ��STL map
        std::string szSource;               // Դ�����ַ���
        std::string szFileName;             // Դ�����ļ���
        std::string szBuffer;               // ���ʻ�����
        int iRow;                           // ��ǰ�к�
        int iNonTerminal;                   // ��ǰ���ս�״̬���
        int iPos;                           // Դ���뵱ǰ��ȡλ��ָ��
        std::vector<CToken>  pTokenList;    // ������
        bool Process(int iTag);             // ���ʷ�������
        void EmitToken(const int iKind,const std::string szContent,const int iRow); // ��¼���ʺ���
        void EmitToken(const int iKind,const int iRow);                             // ��¼���ʺ��������غ�����û�б�ע��Ϣ
        bool SearchKeyWord(std::string szKeyWord, int &iPosition);                  // ��ѯ�ؼ��ֱ���
        void BufferBack();                    // ���ʻ��������˺���
        int  ReadFile(std::string szStr);     // ���ļ�����
        void EmitError(std::string szStr);    // ��������
        void SetKeyWords();                   // ���ùؼ��ֱ���
};

#endif // CLEX_H
