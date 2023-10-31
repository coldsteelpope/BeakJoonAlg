#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int arr[100001] = { 0, };
int temp[100001] = { 0, };
int answer[100001] = { 0, };

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

int BinarySearch(int arr_len, int find_num)
{
	int left = 0;
	int right = arr_len - 1;
	int find = false;

	while (left <= right)
	{
		int mid = (left + right) / 2;

		if (find_num < arr[mid])
		{
			right = mid - 1;
		}
		else if (find_num > arr[mid])
		{
			left = mid + 1;
		}
		else
		{
			find = true;
			break;
		}
	}

	if (find)
		return 1;
	else
		return 0;
}

int main(void)
{
	int arr_len = 0;
	scanf("%d", &arr_len);
	for (int i = 0; i < arr_len; ++i)
		scanf("%d", &arr[i]);
	MergeSort(0, arr_len - 1);

	int answer_len = 0;
	scanf("%d", &answer_len);

	for (int i = 0; i < answer_len; ++i)
	{
		int find_num = 0;
		scanf("%d", &find_num);
		answer[i] = BinarySearch(arr_len, find_num);
	}

	for (int i = 0; i < answer_len; ++i)
	{
		printf("%d\n", answer[i]);
	}

	return 0;
}