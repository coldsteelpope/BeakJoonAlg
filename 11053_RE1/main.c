#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LEN 1001

int arr[MAX_LEN] = { 0, };
int dp[MAX_LEN] = { 0, };

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
	}

	for (int i = 0; i < N; ++i)
	{
		dp[i] = 1;
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (arr[i] > arr[j])
			{
				dp[i] = GetMax(dp[j] + 1, dp[i]);
			}
		}
	}

	// 밑에 있는 코드를 추가하지 않았을 때 반례
	// [1,2,3,2,1]
	int maxValue = 0;
	for (int i = 0; i < N; ++i)
	{
		maxValue = GetMax(dp[i], maxValue);
	}

	printf("%d\n", maxValue);
	return 0;
}