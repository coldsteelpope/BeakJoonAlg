#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

long long dp[91][2] = { 0, };

int main(void)
{
	int N;
	scanf("%d", &N);
	
	dp[1][0] = 0; dp[2][0] = 1;
	dp[1][1] = 1; dp[2][1] = 0;
	
	for (int n = 3; n <= N; ++n)
		for (int i = 0; i <= 1; ++i)
			dp[n][i] = dp[n - 1][i] + dp[n - 2][i];

	long long sum = 0;
	for (int i = 0; i <= 1; ++i)
		sum += dp[N][i];
	
	printf("%lld", sum);
	return 0;
}