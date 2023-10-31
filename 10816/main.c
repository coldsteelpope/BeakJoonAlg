#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int arr[500000] = { 0 };
int temp[500000] = { 0 };
int find[500000] = { 0 };

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
		arr[left + i] = temp[i];
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

int BinarySearchUpperBound(int left, int right, int val)
{
	while (left < right)
	{
		int mid = (right + left) / 2;
		if (val >= arr[mid])
		{
			left = mid + 1;
		}
		else
		{
			right = mid;
		}
	}
	return left;
}

int BinarySearchLowerBound(int left, int right, int val)
{
	while (left < right)
	{
		int mid = (right + left) / 2;
		if (arr[mid] >= val)
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

int BinarySearch(int left, int right, int val)
{
	int result = -1;
	while (left <= right)
	{
		int mid = (right + left) / 2;
		if (arr[mid] > val)
		{
			right = mid - 1;
		}
		else if (arr[mid] < val)
		{
			left = mid + 1;
		}
		else
		{
			result = mid;
			break;
		}
	}
	return result;
}

int main(void)
{
	int N, M;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &arr[i]);
	}
	
	MergeSort(0, N - 1);

	scanf("%d", &M);
	for (int i = 0; i < M; ++i)
	{
		scanf("%d", &find[i]);
	}
	
	for (int i = 0; i < M; ++i)
	{
		if (BinarySearch(0, N - 1, find[i]) == -1)
		{
			find[i] = 0;
		}
		else
		{
			int lower_bound = BinarySearchLowerBound(0, N - 1, find[i]);
			int upper_bound = BinarySearchUpperBound(0, N - 1, find[i]);

			upper_bound = (arr[upper_bound] == find[i]) ? N : upper_bound;
			find[i] = upper_bound - lower_bound;
		}
	}
	
	for (int i = 0; i < M; ++i)
	{
		printf("%d ", find[i]);
	}

	return 0;
}