#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MOD 10007

long long dp[1001][1001] = { 0, };

void SetDP(int N)
{
	dp[1][0] = 1; dp[1][1] = 1;
	for (int i = 2; i <= N; ++i)
	{
		dp[i][i] = 1;
		dp[i][0] = 1;
	}
	for (int i = 2; i <= N; ++i)
		for (int k = 1; k < N; ++k)
			dp[i][k] = (dp[i - 1][k - 1] + dp[i - 1][k]) % MOD;
}

int main(void)
{
	int N, K;
	scanf("%d%d", &N, &K);
	SetDP(N);
	
	printf("%lld", dp[N][K] % MOD);
	return 0;
}