#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int map[1025][1025] = { 0, };
int dp[1025][1025] = { 0, };

void SetDP(int N)
{
	int sum = 0;
	for (int y = 1; y <= N; ++y)
	{
		sum += map[y][1];
		dp[y][1] = sum;
	}

	sum = 0;
	for (int x = 1; x <= N; ++x)
	{
		sum += map[1][x];
		dp[1][x] = sum;
	}

	for (int y = 2; y <= N; ++y)
	{
		for (int x = 2; x <= N; ++x)
		{
			dp[y][x] = dp[y][x - 1] + dp[y - 1][x] - dp[y - 1][x - 1] + map[y][x];
		}
	}
}

void SetMap(int N)
{
	for (int y = 1; y <= N; ++y)
		for (int x = 1; x <= N; ++x)
			scanf("%d", &map[y][x]);
}

void PrintDP(int N)
{
	printf("\n");
	for (int y = 1; y <= N; ++y)
	{
		for (int x = 1; x <= N; ++x)
		{
			printf("%d\t", dp[y][x]);
		}
		printf("\n");
	}
	printf("\n");
}

int main(void)
{
	int N, M;
	scanf("%d%d", &N, &M);
	
	SetMap(N);
	SetDP(N);
	//PrintDP(N);

	for (int i = 0; i < M; ++i)
	{
		int row1, col1, row2, col2;
		scanf("%d%d%d%d", &row1, &col1, &row2, &col2);

		int sum = dp[row2][col2] - dp[row1 - 1][col2] - dp[row2][col1 - 1] + dp[row1 - 1][col1 - 1];
		printf("%d\n", sum);
	}
	return 0;
}