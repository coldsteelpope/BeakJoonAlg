#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define REMAINDER 1000000000

long long dp[101][10] = { 0, };

int main(void)
{
	int N;
	scanf("%d", &N);

	// Ãß°¡
	dp[1][0] = 1;
	for (int i = 1; i <= 9; ++i)
		dp[1][i] = 1;

	for (int n = 2; n <= N; ++n)
	{
		dp[n][0] = (dp[n - 1][1]) % REMAINDER;
		for (int j = 1; j <= 8; ++j)
		{
			dp[n][j] = (dp[n - 1][j - 1] + dp[n - 1][j + 1]) % REMAINDER;
		}
		dp[n][9] = (dp[n - 1][8]) % REMAINDER;
	}

	long long sum = 0;
	for (int i = 1; i <= 9; ++i)
		sum = (sum + dp[N][i]) % REMAINDER;
	printf("%lld", sum);
	return 0;
}