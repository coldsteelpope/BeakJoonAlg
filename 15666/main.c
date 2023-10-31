#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int nums[10] = { 0, };
int temp[10] = { 0, };
int serial[10] = { 0, };

void MergeResult(int left, int mid, int right)
{
	int leftIdx = left;
	int rightIdx = mid + 1;
	int tempIdx = 0;

	while (leftIdx <= mid && rightIdx <= right)
	{
		if (nums[leftIdx] < nums[rightIdx])
			temp[tempIdx++] = nums[leftIdx++];
		else
			temp[tempIdx++] = nums[rightIdx++];
	}

	if (mid < leftIdx)
	{
		while (rightIdx <= right)
			temp[tempIdx++] = nums[rightIdx++];
	}
	else
	{
		while (leftIdx <= mid)
			temp[tempIdx++] = nums[leftIdx++];
	}

	for (int i = 0; i < tempIdx; ++i)
	{
		nums[left + i] = temp[i];
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

void GetAnswer(int select_num, int select_num_max, int max_index, int serial_index, int ex_num)
{
	if (select_num == 0)
	{
		for (int i = 0; i < select_num_max; ++i)
			printf("%d ", serial[i]);
		printf("\n");
	}
	else
	{
		int last_num = 0;
		for (int i = 0; i < max_index; ++i)
		{
			if (last_num != nums[i] && ex_num <= nums[i])
			{
				serial[serial_index] = nums[i];
				last_num = nums[i];
				GetAnswer(select_num - 1, select_num_max, max_index, serial_index + 1, nums[i]);
			}
		}
	}
}

int main(void)
{
	int N, M;
	scanf("%d%d", &N, &M);
	
	for (int i = 0; i < N; ++i)
		scanf("%d", &nums[i]);
	MergeSort(0, N - 1);
	GetAnswer(M, M, N, 0, 0);
	return 0;
}