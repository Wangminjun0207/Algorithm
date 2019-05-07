#include <stdio.h>
#include <stdlib.h>
int dp[16][16];
int main()
{
    int T; // 数塔数量
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        int n; // 数塔层数
        scanf("%d",&n);
        /* 初始化数塔 */
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=i;j++)
            {
                scanf("%d",&dp[i][j]);
            }
        }

        /* 动态规划求最优解 */
        for(int i=n-1;i>=1;i--)
        {
            for(int j=1;j<=i;j++)
            {
                dp[i][j] += dp[i+1][j]>dp[i+1][j+1]?dp[i+1][j]:dp[i+1][j+1]; // 动态规划
            }
        }
        printf("%d\n",dp[1][1]); // 输出最优解
    }
    return 0;
}
