#include <stdio.h>
#include <string.h>
// 求nextval数组
void getNextval(char *p_nextval, int nextval[])
{
	int j, k;
	nextval[0] = k = -1;
	j = 1;
	while(p_nextval[j])
	{
		if(k==-1 || p_nextval[j-1]==p_nextval[k])
			if(p_nextval[++k]==p_nextval[j])
				nextval[j++] = nextval[k];
			else
				nextval[j++] = k;
		else
			k = nextval[k];
	}
}

int main()
{
	char a[5] = "aaab";
	char t[10] = "abcabaa";
	char u[25] = "abcaabbabcabaacbacba";
	int a_nextval[5];
	int t_nextval[10];
	int u_nextval[20];
	getNextval(a,a_nextval);
	getNextval(t,t_nextval);
	getNextval(u,u_nextval);
	int count = 0;
	int len = strlen(a);
	printf("a_nextval:");
	while(count<len)
		printf("%4d",a_nextval[count++]);
	printf("\n");
	count = 0;
	len = strlen(t);
	printf("t_nextval:");
	while(count<len)
		printf("%4d",t_nextval[count++]);
	printf("\n");
	count = 0;
	len = strlen(u);
	printf("a_nextval:");
	while(count<len)
		printf("%4d",u_nextval[count++]);
	printf("\n");
}
