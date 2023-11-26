#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LEN 501

int board[MAX_LEN][MAX_LEN] = { 0, };
long long int dp[MAX_LEN][MAX_LEN] = { 0, };

int M, N;
int dirs[4][2] = {
	{ +0, +1 },
	{ +1, +0 },
	{ +0, -1 },
	{ -1, +0 }
};

void PrintDP();

long long int DFS(int currentY, int currentX)
{
	if (currentY == M - 1 && currentX == N - 1)
	{
		return 1;
	}

	if (dp[currentY][currentX] != -1)
	{
		return dp[currentY][currentX];
	}

	dp[currentY][currentX] = 0;
	long long int numberOfCases = 0;

	for (int dirIdx = 0; dirIdx < 4; ++dirIdx)
	{
		int nextY = currentY + dirs[dirIdx][0];
		int nextX = currentX + dirs[dirIdx][1];

		if (nextY < 0 || nextX < 0 || nextY >= M || nextX >= N)
		{
			continue;
		}

		if (board[currentY][currentX] <= board[nextY][nextX])
		{
			continue;
		}
		numberOfCases += DFS(nextY, nextX);
	}

	dp[currentY][currentX] = numberOfCases;
	return dp[currentY][currentX];
}

void SetBoard()
{
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			scanf("%d", &board[i][j]);
			dp[i][j] = -1;
		}
	}
}

void PrintDP()
{
	printf("\n");
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (dp[i][j] >= 0)
			{
				printf("+%lld\t", dp[i][j]);
			}
			else
			{
				printf("%lld\t", dp[i][j]);
			}
		}
		printf("\n");
	}
	printf("\n");
}

int main(void)
{
	scanf("%d%d", &M, &N);
	SetBoard(M, N);
	DFS(0, 0);
	printf("%lld\n", dp[0][0]);
	PrintDP();
	return 0;
}

