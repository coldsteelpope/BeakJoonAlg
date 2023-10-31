#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int arr[500000];
int temp[500000];
int freq[8001];

void MergeResult(int left, int mid, int right)
{
	int leftIdx = left;
	int rightIdx = mid + 1;
	int tempIdx = 0;

	while (leftIdx <= mid && rightIdx <= right)
	{
		if (arr[leftIdx] <= arr[rightIdx])
		{
			temp[tempIdx++] = arr[leftIdx++];
		}
		else
		{
			temp[tempIdx++] = arr[rightIdx++];
		}
	}

	if (leftIdx > mid)
	{
		while (rightIdx <= right)
		{
			temp[tempIdx++] = arr[rightIdx++];
		}
	}
	else
	{
		while (leftIdx <= mid)
		{
			temp[tempIdx++] = arr[leftIdx++];
		}
	}

	for (int i = 0; i < tempIdx; ++i)
	{
		arr[i + left] = temp[i];
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

int GetSum(int left, int right)
{
	int sum = 0;
	for (int i = left; i < right; ++i)
	{
		sum += arr[i];
	}
	return sum;
}

int main(void)
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
		scanf("%d", &arr[i]);

	MergeSort(0, N - 1);
	
	int sum = GetSum(0, N);
	int avg = round(GetSum(0, N) / (double)N);
	
	int midVal = arr[(N + 0) / 2];

	int maxFreq = -1;
	int maxFreqIdx = -1;

	for (int i = 0; i < N; ++i)
	{
		++freq[arr[i] + 4000];
		if (maxFreq < freq[arr[i] + 4000])
		{
			maxFreq = freq[arr[i] + 4000];
			maxFreqIdx = arr[i] + 4000;
		}
	}

	int secondMinFreq = -1;
	int secondMinFreqIdx = -1;
	for (int i = 0; i < 8001; ++i)
	{
		if (maxFreq == freq[i] && maxFreqIdx != i)
		{
			secondMinFreqIdx = i;
			break;
		}
	}

	int range = arr[N - 1] - arr[0];
	printf("%d\n", avg);
	printf("%d\n", midVal);
	if (secondMinFreqIdx != -1)
		printf("%d\n", secondMinFreqIdx - 4000);
	else
		printf("%d\n", maxFreqIdx - 4000);
	printf("%d\n", range);
	return 0;
}