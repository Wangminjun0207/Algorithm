#include "Predefine.h"
// 访问节点数据域
void visit(const BiTree bt)
{
    if(bt)
        std::cout << bt->data;
}
