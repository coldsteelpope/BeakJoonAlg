#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int map[1001][1001] = { 0, };
int dp[1001][1001] = { 0, };

int GetMax(int a, int b)
{
	return a > b ? a : b;
}

void SetMap(int N, int M)
{
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j)
			scanf("%d", &map[i][j]);
}

void PrintDP(int N, int M)
{
	printf("\n");
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			printf("%d\t", dp[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void SetDP(int N, int M)
{
	dp[1][1] = map[1][1];
	for (int i = 2; i <= N; ++i)
		dp[i][1] = dp[i - 1][1] + map[i][1];
	for (int j = 2; j <= M; ++j)
		dp[1][j] = dp[1][j - 1] + map[1][j];

	for (int i = 2; i <= N; ++i)
	{
		for (int j = 2; j <= M; ++j)
		{
			int path_one = dp[i - 1][j] + map[i][j];
			int path_two = dp[i][j - 1] + map[i][j];
			dp[i][j] = GetMax(path_one, path_two);
		}
	}
}

int main(void)
{
	int N, M;
	scanf("%d%d", &N, &M);
	
	SetMap(N, M);
	SetDP(N, M);
	printf("%d", dp[N][M]);
	return 0;
}