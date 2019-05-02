#include "Predefine.h"
#include <string.h>
extern BiT createBiTree(char *preorder, char *midorder, int *i, int first, int last);
extern void preorderTree(const BiT bt);
int main()
{
	int i = 0;
	printf("please input preorder array:");
	char preorder[64];
	scanf("%s",preorder);
	printf("please input midorder array:");
	char midorder[64];
	scanf("%s",midorder);
	BiT bt = createBiTree(preorder,midorder,&i,0,strlen(preorder)-1);
	preorderTree(bt);
	return 0;
}
