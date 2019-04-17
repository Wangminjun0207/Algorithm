// 求出nextval数组的值
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
