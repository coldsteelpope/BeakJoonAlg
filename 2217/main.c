
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int ropes[100001] = { 0, };
int temp[100001] = { 0, };

void MergeResult(int left, int mid, int right)
{
	int leftIdx = left;
	int rightIdx = mid + 1;
	int tempIdx = 0;

	while (leftIdx <= mid && rightIdx <= right)
	{
		if (ropes[leftIdx] > ropes[rightIdx])
		{
			temp[tempIdx++] = ropes[leftIdx++];
		}
		else
		{
			temp[tempIdx++] = ropes[rightIdx++];
		}
	}

	if (mid < leftIdx)
	{
		while (rightIdx <= right)
		{
			temp[tempIdx++] = ropes[rightIdx++];
		}
	}
	else
	{
		while (leftIdx <= mid)
		{
			temp[tempIdx++] = ropes[leftIdx++];
		}
	}

	for (int i = 0; i < tempIdx; ++i)
	{
		ropes[left + i] = temp[i];
	}
}

void MergeSort(int left, int right)
{
	if (left >= right)
		return;
	int mid = (left + right) / 2;
	MergeSort(left, mid);
	MergeSort(mid + 1, right);
	MergeResult(left, mid, right);
}

int main(void)
{
	int N;
	scanf("%d", &N);

	for (int i = 1; i <= N; ++i)
	{
		scanf("%d", &ropes[i]);
	}

	MergeSort(1, N);

	long long max_w = ropes[1];
	for (int k = 2; k <= N; ++k)
	{
		long long weight = ropes[k] * k;
		if (weight >= max_w)
			max_w = weight;
	}
	
	printf("%lld", max_w);
	return 0;
}