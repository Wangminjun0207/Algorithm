#include "Predefine.h"
#include <string.h>
extern BiT createBiTree(char *preorder, char *midorder, int *i, int first, int last);
int main()
{
	int i = 0;
	printf("please input preorder array:");
	char preorder[64];
	scanf("%s",preorder);
	printf("please input midorder array:");
	char midorder[64];
	scanf("%s",midorder);
	createBiTree(preorder,midorder,&i,0,strlen(preorder)-1);
	return 0;
}
