/** ����ͼʮ������洢 */

#include "Predefine.h"

extern int crtGraph(OLGraph &graph);
int main()
{
    OLGraph graph;
    if(crtGraph(graph)==0)
    {
        std::cout << "create graph successful!" << std::endl;
    }
    return 0;
}
