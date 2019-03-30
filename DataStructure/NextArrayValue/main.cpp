#include <stdio.h>
#include <string.h>
// 求next数组
void getNext(char *p_next, int next[])
{
	int j, k;
	next[0] = k = -1;
	j = 1;
	while(p_next[j])
	{
		if(k==-1 || p_next[j-1]==p_next[k])
			next[j++] = ++k;
		else
			k = next[k];
	}
}

int main()
{
	char a[5] = "aaab";
	char t[10] = "abcabaa";
	char u[25] = "abcaabbabcabaacbacba";
	int a_next[5];
	int t_next[10];
	int u_next[20];
	getNext(a,a_next);
	getNext(t,t_next);
	getNext(u,u_next);
	int count = 0;
	int len = strlen(a);
	printf("a_next:");
	while(count<len)
		printf("%4d",a_next[count++]);
	printf("\n");
	count = 0;
	len = strlen(t);
	printf("t_next:");
	while(count<len)
		printf("%4d",t_next[count++]);
	printf("\n");
	count = 0;
	len = strlen(u);
	printf("a_next:");
	while(count<len)
		printf("%4d",u_next[count++]);
	printf("\n");
}
