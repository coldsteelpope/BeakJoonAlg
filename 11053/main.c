#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int arr[1001] = { 0, };
int memo[1001] = { 0, };
int memo_len = 0;

int BinarySearchLower(int left, int right, int target)
{
	while (left < right)
	{
		int mid = (left + right) / 2;
		if (memo[mid] >= target)
		{
			right = mid;
		}
		else
		{
			left = mid + 1;
		}
	}
	return right;
}

int main(void)
{
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; ++i)
		scanf("%d", &arr[i]);


	memo[0] = arr[0];
	memo_len++;

	for (int i = 1; i < N; ++i)
	{
		if (arr[i] > memo[memo_len - 1])
		{
			memo[memo_len++] = arr[i];
		}
		else
		{
			int pos = BinarySearchLower(0, memo_len - 1, arr[i]);
			memo[pos] = arr[i];
		}
	}
	printf("%d", memo_len);

	return 0;
}