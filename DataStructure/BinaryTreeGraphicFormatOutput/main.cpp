/* 设二叉树采用二叉链表存储结构，结点数据域为字符类型。编写控制台应用程序采用
 * 先序遍历法建立二叉树存储结构并实现二叉树的字符图形显示。输入及输出示例如下：
 * 输入: ABDH##I##EJ##K##CFL##M##GN##O##     (#表示NULL指针域，表示回车键)
 * 输出:
 *               A               行1
 *       ________|________       行2  横线由至少2个下划线字符组成，竖线是一个|字符
 *       |               |       行3
 *       B               C       行4
 *   ____|____       ____|____   行5
 *   |       |       |       |   行6
 *   D       E       F       G   行7
 * __|__   __|__   __|__   __|__ 行8  (行8的每根水平线由2个下划线字符组成)
 * |   |   |   |   |   |   |   | 行9
 * H   I   J   K   L   M   N   O 行10
 */

#include "Predefine.h"
extern BiTree CrtBT();
extern int LayerTraval(BiTree bt);
extern void printTree(std::vector<ElemTp> tree);
std::vector<ElemTp> List;
int main()
{
    BiTree bt = CrtBT();
    LayerTraval(bt);
    std::cout << std::endl;
	printTree(List);
    return 0;
}
