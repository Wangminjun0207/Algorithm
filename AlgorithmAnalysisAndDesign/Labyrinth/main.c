#include <stdio.h>
int maze[9][9] = {
{2,2,2,2,2,2,2,2,2},
{2,0,0,0,0,0,0,0,2},
{2,0,2,2,0,2,2,0,2},
{2,0,2,0,0,2,0,0,2},
{2,0,2,0,2,0,2,0,2},
{2,0,0,0,0,0,2,0,2},
{2,2,0,2,2,0,2,2,2},
{2,0,0,0,0,0,0,0,2},
{2,2,2,2,2,2,2,2,2}
};

void visit(int i, int j)
{
	int m,n;
	maze[i][j] = 1;
	if(i==7 && j==7)
	{
		printf("\n��ʾ·����\n");
		for(m=0;m<9;m++)
		{
			for(n=0;n<9;n++)
			{
				if(maze[m][n]==2)
				{
					printf("��");
				}
				else if(maze[m][n]==1)
				{
					printf("+ ");

				}
				else
				{
					printf("  ");
				}
			}
			printf("\n");
		}
	}
	if(maze[i][j+1] == 0) visit(i, j+1);
	if(maze[i+1][j] == 0) visit(i+1, j);
	if(maze[i][j-1] == 0) visit(i, j-1);
	if(maze[i-1][j] == 0) visit(i-1, j);
	maze[i][j] = 0; // ����߲�ͨ���߹���·Ҫ���� 
}
int main()
{
	int i,j;
	printf("��ʾ�Թ���\n");
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			if(maze[i][j]==2)
			{
				printf("��");
			}
			else{
				printf("  ");
			}
		}
		printf("\n");
	}
	visit(1,1);
	return 0;
}
