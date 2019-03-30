// s为一个字符串，将子串t用p替换
int index_kmp(char *s, char *t, char *p, int nextval[])
{
	int i, j;
	i = j = 0;
	int count = 0;
	while(s[i])
	{
		while(s[i]&&t[j])
		{
			if(j==-1 || s[i]==t[j])
			{
				i++;
				j++;
			}
			else
				j = nextval[j];
		}
		if(!t[j])
		{
			count++;
			i = i - j;
			j = 0;
			while(p[j])
			{
				s[i] = p[j];
				i++;
				j++;
			}
		}
		j = 0;

	}
	return count>0?count:-1;
}
