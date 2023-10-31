#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MOD 10007

long long dp[10] = { 0, };

int main(void)
{
	long long N;
	scanf("%lld", &N);

	for (int i = 0; i < 10; ++i)
		dp[i] = 1;

	for (long long i = 1; i < N; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			for (int pointer = j + 1; pointer < 10; ++pointer)
			{
				dp[j] = (dp[j] + dp[pointer]) % MOD;
			}
		}
	}
	
	long long sum = 0;
	for (int i = 0; i < 10; ++i)
		sum = (sum + dp[i]) % MOD;

	printf("%lld\n", sum);
	return 0;
}