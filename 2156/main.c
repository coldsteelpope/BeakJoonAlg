#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int wines[10001] = { 0, };
int dp[10001] = { 0, };

int GetMax(int a, int b)
{
	return a > b ? a : b;
}

int main(void)
{
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; ++i)
		scanf("%d", &wines[i]);

	dp[0] = 0;
	dp[1] = wines[1];
	dp[2] = wines[1] + wines[2];
	
	for (int i = 3; i <= n; ++i)
	{
		int temp = GetMax(dp[i - 3] + wines[i - 1] + wines[i], dp[i - 2] + wines[i]);
		dp[i] = GetMax(dp[i - 1], temp);
	}

	printf("%d\n", dp[n]);
	return 0;
}