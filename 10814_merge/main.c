#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void MergeResult(int v[], int left, int mid, int right)
{
	int leftIdx = left;
	int rightIdx = mid + 1;

	int* temp = (int*)malloc(sizeof(int) * right);
	int tempIdx = 0;

	while (leftIdx <= mid && rightIdx <= right)
	{
		if (v[leftIdx] <= v[rightIdx])
		{
			temp[tempIdx++] = v[leftIdx];
			leftIdx++;
		}
		else
		{
			temp[tempIdx++] = v[rightIdx];
			rightIdx++;
		}
	}

	// 나머지 채우기
	if (leftIdx > mid)
	{
		while (rightIdx <= right)
		{
			temp[tempIdx++] = v[rightIdx];
			rightIdx++;
		}
	}
	else
	{
		while (leftIdx <= mid)
		{
			temp[tempIdx++] = v[leftIdx];
			leftIdx++;
		}
	}

	for (int i = 0; i < tempIdx; ++i)
	{
		v[left + i] = temp[i];
	}
	temp = NULL;
	free(temp);
}

void MergeSort(int v[], int left, int right)
{
	if (left >= right)
		return;
	int mid = (left + right) / 2;
	MergeSort(v, left, mid);
	MergeSort(v, mid + 1, right);
	MergeResult(v, left, mid, right);
}

int main(void)
{
	int arr[] = { 3,2,5,7,6,1,8 };
	size_t arr_len = sizeof(arr) / sizeof(int);
	MergeSort(arr, 0, arr_len - 1);


}