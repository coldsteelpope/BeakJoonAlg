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
	{
		scanf("%d", &arr[i]);
		dp[i] = arr[i];
	}

	int max_value = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (arr[j] < arr[i] && dp[i] < dp[j] + arr[i])
			{
				dp[i] = dp[j] + arr[i];
			}
		}
		max_value = GetMax(max_value, dp[i]);
	}

	printf("%d", max_value);
	return 0;
}