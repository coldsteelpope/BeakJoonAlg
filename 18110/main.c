#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int comments[3000000];
int temp[3000000];

void MergeResult(int left, int mid, int right)
{
	int leftIdx = left;
	int rightIdx = mid + 1;
	int tempIdx = 0;

	while (leftIdx <= mid && rightIdx <= right)
	{
		if (comments[leftIdx] <= comments[rightIdx])
		{
			temp[tempIdx++] = comments[leftIdx++];
		}
		else
		{
			temp[tempIdx++] = comments[rightIdx++];
		}
	}

	if (leftIdx > mid)
	{
		while (rightIdx <= right)
		{
			temp[tempIdx++] = comments[rightIdx++];
		}
	}
	else
	{
		while (leftIdx <= mid)
		{
			temp[tempIdx++] = comments[leftIdx++];
		}
	}

	for (int i = 0; i < tempIdx; ++i)
	{
		comments[left + i] = temp[i];
	}
}

void MergeSort(int left, int right)
{
	if (left >= right)
		return;
	int mid = (right + left) / 2;
	MergeSort(left, mid);
	MergeSort(mid + 1, right);
	MergeResult(left, mid, right);
}

int main(void)
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &comments[i]);
	
	if (n == 0)
	{
		printf("0");
	}
	else
	{
		MergeSort(0, n - 1);
		int abandonedNum = (int)(round((double)n * 0.15));

		double sum = 0;
		for (int i = 0 + abandonedNum; i < n - abandonedNum; ++i)
			sum += (double)comments[i];
		double rounded_sum = round(sum / (n - (abandonedNum * 2)));

		printf("%d", (int)rounded_sum);
	}
	return 0;
}