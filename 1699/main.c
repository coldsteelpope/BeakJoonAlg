#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define INF (~0U >> 2)

int dp[100001] = { 0, };

int GetMin(int a, int b)
{
	return a > b ? b : a;
}

int main(void)
{
	int N;
	scanf("%d", &N);

	for (int i = 0; i <= N; ++i)
		dp[i] = INF;
	
	dp[0] = 0; dp[1] = 1; dp[2] = 2; dp[3] = 3;
	for (int i = 4; i <= N; ++i)
	{
		for (int j = 1; j * j <= i; ++j)
		{
			dp[i] = GetMin(dp[i], dp[i - j * j] + 1);
		}
	}

	printf("%d", dp[N]);
	return 0;
}