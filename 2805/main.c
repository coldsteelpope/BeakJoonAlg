#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

long long trees[1000000] = { 0, };
long long temp[1000000] = { 0, };

void MergeResult(long long left, long long mid, long long right)
{
	long long leftIdx = left;
	long long rightIdx = mid + 1;
	long long tempIdx = 0;

	while (leftIdx <= mid && rightIdx <= right)
	{
		if (trees[leftIdx] >= trees[rightIdx])
		{
			temp[tempIdx++] = trees[leftIdx++];
		}
		else
		{
			temp[tempIdx++] = trees[rightIdx++];
		}
	}

	if (leftIdx > mid)
	{
		while (rightIdx <= right)
		{
			temp[tempIdx++] = trees[rightIdx++];
		}
	}
	else
	{
		while (leftIdx <= mid)
		{
			temp[tempIdx++] = trees[leftIdx++];
		}
	}

	for (long long i = 0; i < tempIdx; ++i)
	{
		trees[left + i] = temp[i];
	}
}

void MergeSort(long long left, long long right)
{
	if (left >= right)
		return;
	long long mid = (left + right) / 2;
	MergeSort(left, mid);
	MergeSort(mid + 1, right);
	MergeResult(left, mid, right);
}

int main(void)
{
	long long N, M;
	scanf("%lld%lld", &N, &M);
	
	for (long long i = 0; i < N; ++i)
		scanf("%lld", &trees[i]);
	
	MergeSort(0, N - 1);
	
	long long max = trees[0];
	long long min = 0;

	while (min < max)
	{
		long long mid = (max + min) / 2;
		long long sum = 0;

		for (int i = 0; i < N; ++i)
		{
			if(trees[i] - mid > 0)
				sum += (trees[i] - mid);
		}

		if (sum < M)
		{
			max = mid;
		}
		else
		{
			min = mid + 1;
		}
	}

	printf("%lld\n", min - 1);

	return 0;
}