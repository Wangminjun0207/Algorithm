#include <iostream>
int main()
{
	int height[20]; // 记录导弹的高度
	int count;      // 记录导弹数量
	int dp[20];     // 记录目前可以拦截的导弹最大数量
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
	// 找出最大的数量 
	for(int i=1;i<=count;i++)
	{
		max_count = std::max(max_count, dp[i]);
	}
	std::cout << max_count << std::endl;
} 
