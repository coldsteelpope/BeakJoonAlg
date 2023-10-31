#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int arr[1001] = { 0, };
int dp[1001] = { 0, };

int GetMax(int a, int b)
{
	return a > b ? a : b;
}

int main(void)
{
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; ++i)
		scanf("%d", &arr[i]);

	dp[0] = 1;
	for (int i = 1; i < N; ++i)
	{
		dp[i] = 1;
		for (int j = 0; j < i; ++j)
		{
			if (arr[i] > arr[j])
				dp[i] = GetMax(dp[i], dp[j] + 1);
		}
	}

	int max = 0;
	for (int i = 0; i < N; ++i)
	{
		max = (dp[i] > max) ? dp[i] : max;
	}

	printf("%d", max);
	return 0;
}