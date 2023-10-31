#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MOD 9901

long long dp[100001] = { 0, };

int main(void)
{
	dp[1] = 3 % MOD;
	dp[2] = 7 % MOD;
	long long N;
	scanf("%lld", &N);

	for (long long i = 3; i <= N; ++i)
	{
		dp[i] = (2 * dp[i - 1] + dp[i - 2]) % MOD;
	}

	printf("%lld\n", dp[N]);
	return 0;
}