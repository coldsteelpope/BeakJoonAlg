#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

long long dp[100001][4] = { 0, };

int main(void)
{
	int testcase = 0;
	scanf("%d", &testcase);

	dp[1][1] = 1;
	dp[2][2] = 1;
	dp[3][1] = 1; dp[3][2] = 1; dp[3][3] = 1;

	for (int t = 0; t < testcase; ++t)
	{
		int num = 0;
		scanf("%d", &num);
		
		for (int n = 4; n <= num; ++n)
		{
			dp[n][1] = (dp[n - 1][2] + dp[n - 1][3]) % 1000000009;
			dp[n][2] = (dp[n - 2][1] + dp[n - 2][3]) % 1000000009;
			dp[n][3] = (dp[n - 3][1] + dp[n - 3][2]) % 1000000009;
		}
		
		long long sum = 0;
		for (int i = 1; i <= 3; ++i)
			sum += dp[num][i];
		sum %= 1000000009;
		printf("%ld\n", sum);
	}

	return 0;
}