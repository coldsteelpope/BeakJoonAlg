#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int Partition(int arr[], int left, int right)
{
	int pivot = arr[left];
	int low = left + 1;
	int high = right;

	while (low <= high)
	{
		while (low <= right && arr[low] <= pivot)
		{
			low++;
		}

		while (high >= left + 1 && arr[high] >= pivot)
		{
			--high;
		}
		if (low < high)
		{
			swap(&arr[low], &arr[high]);
		}
	}
	swap(&arr[left], &arr[high]);
	return high;
}

void QuickSort(int arr[], int left, int right)
{
	if (left > right)
		return;
	int mid = Partition(arr, left, right);
	QuickSort(arr, left, mid - 1);
	QuickSort(arr, mid + 1, right);
}

int main(void)
{
	int N;
	scanf("%d", &N);
	int* arr = (int*)malloc(sizeof(int) * N);
	for (int arrIdx = 0; arrIdx < N; ++arrIdx)
	{
		scanf("%d", &arr[arrIdx]);
	}
	QuickSort(arr, 0, N - 1);
	for (int i = 0; i < N; ++i)
	{
		printf("%d\n", arr[i]);
	}
	free(arr);
	arr = NULL;
	return 0;
}