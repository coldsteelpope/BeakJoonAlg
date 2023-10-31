#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int serial[10001] = { 0, };
int arr[10001] = { 0, };
int dp[10001] = { 0, };
int dp_idx[10001] = { 0, };

int serial_idx = 0;
int dp_idx_len = 0;
int dp_len = 0;


int BinarySearchLowerBound(int left, int right, int target)
{
	while (left < right)
	{
		int mid = (left + right) / 2;
		if (target <= dp[mid])
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
		scanf("%d", &arr[i]);

	dp[dp_len++] = arr[0];
	dp_idx[dp_idx_len++] = 1;
	
	int max = 1;
	for (int i = 1; i < N; ++i)
	{
		int arr_ele = arr[i];
		
		if (arr_ele > dp[dp_len - 1])
		{
			dp[dp_len++] = arr_ele;
			dp_idx[dp_idx_len] = max + 1;

			++dp_idx_len;
			++max;
		}
		else
		{
			int dp_index = BinarySearchLowerBound(0, dp_len - 1, arr_ele);
			dp[dp_index] = arr_ele;
			dp_idx[dp_idx_len++] = dp_index + 1;
		}
			
	}
	printf("%d\n", dp_len);


	
	for (int i = dp_idx_len - 1; i >= 0; --i)
	{
		if (dp_idx[i] == max)
		{
			serial[serial_idx] = arr[i];
			serial_idx++;
			--max;
		}
			

		if (max == 0)
			break;
	}

	for (int i = serial_idx - 1; i >= 0; --i)
	{
		printf("%d ", serial[i]);
	}

	return 0;
}