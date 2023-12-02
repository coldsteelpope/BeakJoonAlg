#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LEN 500001

int g_getCards[MAX_LEN] = { 0, };
int g_temp[MAX_LEN] = { 0, };
int g_result[MAX_LEN] = { 0, };

void MergeResult(int left, int mid, int right)
{
	int lowPointer = left;
	int highPointer = mid + 1;
	int tempIdx = 0;

	while (lowPointer <= mid && highPointer <= right)
	{
		if (g_getCards[lowPointer] <= g_getCards[highPointer])
		{
			g_temp[tempIdx++] = g_getCards[lowPointer++];
		}
		else
		{
			g_temp[tempIdx++] = g_getCards[highPointer++];
		}
	}

	if (mid < lowPointer)
	{
		while (highPointer <= right)
		{
			g_temp[tempIdx++] = g_getCards[highPointer++];
		}
	}
	else
	{
		while (lowPointer <= mid)
		{
			g_temp[tempIdx++] = g_getCards[lowPointer++];
		}
	}

	for (int i = 0; i < tempIdx; ++i)
	{
		g_getCards[left + i] = g_temp[i];
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

// arr = [ -3, -2, -1 ]
// candidates = [ 0, 1 ]
// arr 배열 5000001번째 원소 값은 0이므로, N까지 비교하면 두 포인터(left, right)가 맨 마지막 원소를 가르키게 되어
// 0 원소가 있다고 판단한다. 따라서, N - 1까지 비교해야 한다.

int BinarySearchLowerBound(int left, int right, int value)
{
	while (left < right)
	{
		int mid = (left + right) / 2;
		if (g_getCards[mid] >= value)
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
	for (int n = 0; n < N; ++n)
	{
		scanf("%d", &g_getCards[n]);
	}
	MergeSort(0, N - 1);
	
	int M;
	scanf("%d", &M);
	for (int m = 0; m < M; ++m)
	{
		int num;
		scanf("%d", &num);
		int idx = BinarySearchLowerBound(0, N - 1, num);
		if (g_getCards[idx] == num)
		{
			g_result[m] = 1;
		}
		else
		{
			g_result[m] = 0;
		}
	}
	
	for (int i = 0; i < M; ++i)
	{
		printf("%d ", g_result[i]);
	}
	return 0;
}