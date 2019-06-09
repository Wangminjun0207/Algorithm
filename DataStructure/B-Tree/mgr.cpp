#include <iostream>
#include <vector>
#include <cstdlib>
#include "Predefine.h"

extern void Menu();
extern void BSubTSearch(BSubT t, KeyTp key);
extern void Layorder(BSubT bt);
extern BSubT BSubTCreate();//根据文件创建b树
extern BSubT BSubTInsert(BSubT t,int key);
extern int BTNodeDelete(BSubTNode *p,int k);

// 控制程序函数， 减少main函数负担
void Mgr()
{
    BSubT bt;
    bt = BSubTCreate();
    char select; // 选择的操作
    int key; // 要删除或者插入或者查找的关键字
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
