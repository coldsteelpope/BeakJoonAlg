#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int triangle[501][501] = { 0, };
int dp[501][501] = { 0, };

int GetMax(int a, int b)
{
	return a > b ? a : b;
}

void SetDP(int i, int j, int n)
{
	if (j > 1 && j < n)
	{
		dp[i][j] = GetMax(dp[i - 1][j] + triangle[i][j], dp[i - 1][j - 1] + triangle[i][j]);
	}
	else if(j == 1)
	{
		dp[i][j] = dp[i - 1][j] + triangle[i][j];
	}
	else if(j == n)
	{
		dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
	}
}

int main(void)
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= i; ++j)
		{
			scanf("%d", &triangle[i][j]);
		}
	}

	dp[1][1] = triangle[1][1];
	for (int i = 2; i <= n; ++i)
	{
		for (int j = 1; j <= i; ++j)
		{
			SetDP(i, j, n);
		}
	}

	int max_value = 0;
	for (int i = 1; i <= n; ++i)
	{
		max_value = GetMax(max_value, dp[n][i]);
	}
	
	printf("%d", max_value);
	return 0;
}