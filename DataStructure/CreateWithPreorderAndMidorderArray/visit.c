#include "Predefine.h"
// 访问节点数据域
void visit(const BiT bt)
{
    if(bt)
    {
        printf("%c",bt->data);
    }
}
