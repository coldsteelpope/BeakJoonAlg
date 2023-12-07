#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int dp[12] = { 0, };

void SetDP()
{
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int node = 4; node <= 11; ++node)
	{
		for (int j = 1; j <= 3; ++j)
		{
			dp[node] += dp[node - j];
		}
	}
}

int main(void)
{
	SetDP();

	int T;
	scanf("%d", &T);

	for (int testCase = 0; testCase < T; ++testCase)
	{
		int n;
		scanf("%d", &n);
		printf("%d\n", dp[n]);
	}

	return 0;
}