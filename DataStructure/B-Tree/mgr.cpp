#include <iostream>
#include <vector>
#include <cstdlib>
#include "Predefine.h"

extern void Menu();
extern void BSubTSearch(BSubT t, KeyTp key);
extern void Layorder(BSubT bt);
extern BSubT BSubTCreate();//�����ļ�����b��
extern BSubT BSubTInsert(BSubT t,int key);
extern int BTNodeDelete(BSubTNode *p,int k);

// ���Ƴ������� ����main��������
void Mgr()
{
    BSubT bt;
    bt = BSubTCreate();
    char select; // ѡ��Ĳ���
    int key; // Ҫɾ�����߲�����߲��ҵĹؼ���
    while(select!='5')
    {
        Menu();
        std::cin >> select;
        switch(select)
        {
            case '1':
                {
                    std::cout << "Please enter keywords:";
                    std::cin >> key;
                    bt = BSubTInsert(bt, key);
                    BSubTSearch(bt,key);
                    std::cout << std::endl << std::endl;
                    break;
                }
            case '2':
                {
                    std::cout << "Please enter keywords:";
                    std::cin >> key;
                    if(BTNodeDelete(bt,key))
                        std::cout << "Delete success!" << std::endl << std::endl;
                    break;
                }
            case '3':
                {
                    std::cout << "Please enter keywords:";
                    std::cin >> key;
                    BSubTSearch(bt,key);
                    std::cout << std::endl << std::endl;
                    break;
                }
            case '4':
                {
                    Layorder(bt);
                    std::cout << std::endl << std::endl;
                    break;
                }
        }
    }
}
