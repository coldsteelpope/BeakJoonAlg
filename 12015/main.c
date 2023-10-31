#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int nums[1000001] = { 0, };
int dp[1000001] = { 0, };
int dp_len = 0;

int BinarySearchLower(int left, int right, int target)
{
	while (left < right)
	{
		int mid = (left + right) / 2;
		if (dp[mid] >= target)
			right = mid;
		else
			left = mid + 1;
	}
	return right;
}

int main(void)
{
	int N;
	scanf("%d", &N);
	
	for (int i = 0; i < N; ++i)
		scanf("%d", &nums[i]);

	dp[0] = nums[0];
	++dp_len;
	
	for (int i = 1; i < N; ++i)
	{
		if (nums[i] > dp[dp_len - 1])
		{
			dp[dp_len++] = nums[i];
		}
		else
		{
			int dp_index = BinarySearchLower(0, dp_len - 1, nums[i]);
			dp[dp_index] = nums[i];
		}
	}
	printf("%d", dp_len);
	return 0;
}