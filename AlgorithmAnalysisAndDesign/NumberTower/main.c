#include <stdio.h>
#include <stdlib.h>
int dp[16][16];
int main()
{
    int T; // ��������
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        int n; // ��������
        scanf("%d",&n);
        /* ��ʼ������ */
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=i;j++)
            {
                scanf("%d",&dp[i][j]);
            }
        }

        /* ��̬�滮�����Ž� */
        for(int i=n-1;i>=1;i--)
        {
            for(int j=1;j<=i;j++)
            {
                dp[i][j] += dp[i+1][j]>dp[i+1][j+1]?dp[i+1][j]:dp[i+1][j+1]; // ��̬�滮
            }
        }
        printf("%d\n",dp[1][1]); // ������Ž�
    }
    return 0;
}
