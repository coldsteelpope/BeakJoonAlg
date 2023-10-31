#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int nums[2][100001] = { 0, };
int dp[2][100001] = { 0, };

int GetMax(int a, int b)
{
	return a > b ? a : b;
}

int main(void)
{
	int T, n;
	scanf("%d", &T);
	
	for (int t = 0; t < T; ++t)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%d", &nums[0][i]);
		for (int i = 0; i < n; ++i)
			scanf("%d", &nums[1][i]);

		dp[0][0] = nums[0][0];
		dp[1][0] = nums[1][0];

		dp[0][1] = dp[1][0] + nums[0][1];
		dp[1][1] = dp[0][0] + nums[1][1];

		for (int i = 2; i < n; ++i)
		{
			dp[0][i] = GetMax(dp[1][i - 1], dp[1][i - 2]) + nums[0][i];
			dp[1][i] = GetMax(dp[0][i - 1], dp[0][i - 2]) + nums[1][i];
		}

		int max_value = 0;
		for (int y = 0; y < 2; ++y)
			for (int x = n - 2; x < n; ++x)
				max_value = (max_value > dp[y][x]) ? max_value : dp[y][x];
		printf("%d\n", max_value);
	}

	return 0;
}