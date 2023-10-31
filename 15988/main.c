#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MOD 1000000009

long long dp[1000001] = { 0, };

int main(void)
{
	long long T;
	scanf("%lld", &T);
	
	for (int t = 0; t < T; ++t)
	{
		long long n;
		scanf("%lld", &n);
		dp[1] = 1 % MOD;
		dp[2] = 2 % MOD;
		dp[3] = 4 % MOD;
		for (long long i = 4; i <= n; ++i)
		{
			dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % MOD;
		}
		printf("%lld\n", dp[n]);
	}
	return 0;
}