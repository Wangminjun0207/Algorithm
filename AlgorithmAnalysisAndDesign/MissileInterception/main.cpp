#include <iostream>
int main()
{
	int height[20]; // ��¼�����ĸ߶�
	int count;      // ��¼��������
	int dp[20];     // ��¼Ŀǰ�������صĵ����������
	std::cin >> count;
	for(int i=1;i<=count;i++)
	{
		std::cin >> height[i];
		dp[i] = 1;
	} 
	for(int i=1;i<=count;i++)
	{
		int max_count = 0; 
		for(int j=1;j<i;j++)
		{
			if(height[j]>=height[i] && max_count<dp[j])
			{
				max_count =  dp[j];
			}
		}
		dp[i] = max_count + 1;
	}
	int max_count = 0;
	// �ҳ��������� 
	for(int i=1;i<=count;i++)
	{
		max_count = std::max(max_count, dp[i]);
	}
	std::cout << max_count << std::endl;
} 
