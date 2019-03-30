#include <stdio.h>
#include <stdlib.h>
extern void getNextval(char *p_nextval, int nextval[]);
extern int index_kmp(char *s, char *t, char*p,  int nextval[]);
int main()
{
	char s[50];
	char t[50];
	char p[50];
	printf("input a string:");
	scanf("%s",s);
	printf("input a string:");
	scanf("%s",t);
	printf("input a string:");
	scanf("%s",p);
	int nextval[50];
	getNextval(t,nextval);
	int count;
	count = index_kmp(s,t,p,nextval);
	if(count>0)
	{
		printf("s :%s\n",s);
		printf("count:%d",count);
	}
	return 0;
}
