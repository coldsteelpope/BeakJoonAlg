#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

long long dp[31][31] = { 0, };

int main(void)
{
	int T;
	scanf("%d", &T);
	
	
	for (int i = 1; i <= 30; ++i)
	{
		dp[i][0] = 1;
		dp[i][i] = 1;
	}

	for (int i = 2; i <= 30; ++i)
	{
		for (int j = 1; j <= i - 1; ++j)
		{
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
		}
	}

	for (int t = 0; t < T; ++t)
	{
		int N, M;
		scanf("%d%d", &N, &M);
		printf("%lld\n", dp[M][N]);
	}

	return 0;
}