#define _CRT_SECURE_NO_WARNINGS

// card에 적힌 num의 값은 음수가 될 수 있다.
// 따라서, 배열에 저장하는 방식으로 lookup table를 활용할 수 없다.

// Sorting에 시간이 많이 걸리므로, O(n^2)의 위험이 있는 quicksort대신 merge sort를 활용하는 것이 좋다.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int arr[500001] = { 0, };
int cards[500001] = { 0, };
int result[500001] = { 0, };

int g_mergeSortTemp[500001] = { 0, };

//void Swap(int* num1, int* num2)
//{
//	int temp = *num1;
//	*num1 = *num2;
//	*num2 = temp;
//}
//
//int Partition(int left, int right)
//{
//	int pivot = arr[left];
//	int lowPointer = left + 1;
//	int highPointer = right;
//
//	while (lowPointer <= highPointer)
//	{
//		while (lowPointer <= right && arr[lowPointer] <= pivot)
//		{
//			++lowPointer;
//		}
//
//		while (highPointer > left && arr[highPointer] >= pivot)
//		{
//			--highPointer;
//		}
//
//		if (lowPointer < highPointer)
//		{
//			Swap(&arr[lowPointer], &arr[highPointer]);
//		}
//	}
//
//	Swap(&arr[left], &arr[highPointer]);
//	return highPointer;
//}
//
//void QuickSort(int left, int right)
//{
//	if (left > right)
//		return;
//	int pivot = Partition(left, right);
//	QuickSort(left, pivot - 1);
//	QuickSort(pivot + 1, right);
//}

void MergeResult(int left, int mid, int right)
{
	int lowerPointer = left;
	int higherPointer = mid + 1;
	int tempIdx = 0;

	while (lowerPointer <= mid && higherPointer <= right)
	{
		if (arr[lowerPointer] < arr[higherPointer])
		{
			g_mergeSortTemp[tempIdx++] = arr[lowerPointer++];
		}
		else
		{
			g_mergeSortTemp[tempIdx++] = arr[higherPointer++];
		}
	}

	if (mid < lowerPointer)
	{
		while (higherPointer <= right)
		{
			g_mergeSortTemp[tempIdx++] = arr[higherPointer++];
		}
	}
	else
	{
		while (lowerPointer <= mid)
		{
			g_mergeSortTemp[tempIdx++] = arr[lowerPointer++];
		}
	}

	for (int i = 0; i < tempIdx; ++i)
	{
		arr[left + i] = g_mergeSortTemp[i];
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

int BinaryLowerBound(int left, int right, int val)
{
	while (left < right)
	{
		int mid = (left + right) / 2;
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

int BinaryUpperBound(int left, int right, int val)
{
	while (left < right)
	{
		int mid = (left + right) / 2;
		if (arr[mid] <= val)
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


int main(void)
{
	int N = 0;
	scanf("%d", &N);
	for (int n = 0; n < N; ++n)
	{
		scanf("%d", &arr[n]);
	}

	MergeSort(0, N - 1);

	int M;
	scanf("%d", &M);
	for (int m = 0; m < M; ++m)
	{
		scanf("%d", &cards[m]);
		int lowerBound = BinaryLowerBound(0, N, cards[m]);
		int upperBound = BinaryUpperBound(0, N, cards[m]);
		result[m] = upperBound - lowerBound;
	}

	for (int i = 0; i < M; ++i)
	{
		printf("%d ", result[i]);
	}

	return 0;
}