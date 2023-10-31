#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int arr[3] = { 0, };

void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int Partition(int left, int right)
{
	int pivot = arr[left];
	int low = left + 1;
	int high = right;

	while (low <= high)
	{
		while (low <= high && pivot >= arr[low])
			++low;
		while (high >= left + 1 && pivot <= arr[high])
			--high;
		if (low < high)
			Swap(&arr[low], &arr[high]);
	}
	Swap(&arr[left], &arr[high]);
	return high;
}

void QuickSort(int left, int right)
{
	if (left > right)
		return;
	int pivot = Partition(left, right);
	QuickSort(left, pivot - 1);
	QuickSort(pivot + 1, right);
}

int main(void)
{
	for (int i = 0; i < 3; ++i)
		scanf("%d", &arr[i]);
	QuickSort(0, 2);
	for (int i = 0; i < 3; ++i)
		printf("%d ", arr[i]);
	return 0;
}
