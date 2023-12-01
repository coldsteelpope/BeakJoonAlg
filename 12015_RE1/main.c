#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LEN 1000001

int arr[MAX_LEN] = { 0, };
int dp[MAX_LEN] = { 0, };

int BinarySearchLowerBound(int left, int right, int value)
{
	while (left < right)
	{
		int mid = (left + right) / 2;
		if (dp[mid] >= value)
		{
			right = mid;
		}
		else
		{
			left = mid + 1;
		}
	}
	return left;
}

int main(void)
{
	int N;
	scanf("%d", &N);
	for (int n = 0; n < N; ++n)
	{
		scanf("%d", &arr[n]);
	}

	int answer = 1;
	dp[0] = arr[0];
	int dpLen = 1;
	for (int i = 1; i < N; ++i)
	{
		int currentValue = arr[i];
		int dpIdx = BinarySearchLowerBound(0, dpLen, currentValue);
		if (dp[dpIdx] < currentValue)
		{
			dp[dpLen++] = currentValue;
		}
		else
		{
			dp[dpIdx] = currentValue;
		}
	}

	printf("%d\n", dpLen);
	return 0;
}