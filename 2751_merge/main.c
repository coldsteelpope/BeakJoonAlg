#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int arr[1000001] = { 0, };

void MergeResult(int left, int mid, int right)
{
	int leftIdx = left;
	int rightIdx = mid + 1;
	
	int* temp = (int*)malloc(sizeof(int) * (right - left + 1));
	int temp_index = 0;

	while (leftIdx <= mid && rightIdx <= right)
	{
		if (arr[leftIdx] <= arr[rightIdx])
		{
			temp[temp_index++] = arr[leftIdx++];
		}
		else
		{
			temp[temp_index++] = arr[rightIdx++];
		}
	}

	if (leftIdx > mid)
	{
		while (rightIdx <= right)
		{
			temp[temp_index++] = arr[rightIdx++];
		}
	}
	else
	{
		while (leftIdx <= mid)
		{
			temp[temp_index++] = arr[leftIdx++];
		}
	}

	for (int i = 0; i < temp_index; ++i)
	{
		arr[left + i] = temp[i];
	}
	free(temp);
	temp = NULL;
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
	
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &arr[i]);
	}

	MergeSort(0, N - 1);

	for (int i = 0; i < N; ++i)
	{
		printf("%d\n", arr[i]);
	}

	return 0;
}