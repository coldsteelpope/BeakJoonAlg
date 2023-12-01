#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int zeroNums = 0;
int oneNums = 0;

int board[128][128] = { 0, };

void DFS(int startY, int startX, int N)
{
	int currentValue = board[startY][startX];
	for (int y = startY; y < startY + N; ++y)
	{
		for (int x = startX; x < startX + N; ++x)
		{
			if (currentValue != board[y][x])
			{
				DFS(startY, startX, N / 2);
				DFS(startY, startX + (N / 2), N / 2);
				DFS(startY + (N / 2), startX, N / 2);
				DFS(startY + (N / 2), startX + (N / 2), N / 2);
				return;
			}
		}
	}
	if (currentValue == 0)
	{
		++zeroNums;
	}
	else if (currentValue == 1)
	{
		++oneNums;
	}
}


void SetBoard(int N)
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			scanf("%d", &board[i][j]);
		}
	}
}

int main(void)
{
	int N;
	scanf("%d", &N);
	SetBoard(N);
	DFS(0, 0, N);
	printf("%d\n%d\n", zeroNums, oneNums);
	return 0;
}