#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int arr[1001] = { 0, };
int dp[1001] = { 0, };
int dp_index = 0;

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
	dp_index++;

	for (int i = 1; i < N; ++i)
	{
		dp[i] = 1;
		for (int j = 0; j < i; ++j)
		{
			if (arr[i] < arr[j])
			{
				dp[i] = GetMax(dp[i], dp[j] + 1);
			}
			else
			{
				dp[i] = GetMax(dp[i], dp[j] - 1);
			}
			//if (arr[i] < arr[j])
			//	dp[i] = GetMax(dp[i], dp[j] + 1);
			
		}
	}

	// 중간에 최종 보스(가장 큰 값이 있을 때) 틀린 코드의 흐름이 꼬여버림
	// Ex) 704, 194, 12, 713, 708, 249
	// Answer DP) 1, 2, 3, 1, 2, 3
	// Wrong DP) 1, 2, 3, 2, 3, 4
	

	int max_value = 0;
	for (int i = 0; i < N; ++i)
	{
		max_value = GetMax(dp[i], max_value);
	}

	printf("%d", max_value);
	return 0;
}