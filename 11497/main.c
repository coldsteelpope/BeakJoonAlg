#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LEN 10001

int heights[MAX_LEN] = { 0, };
int result[MAX_LEN] = { 0, };

int GetAbs(int num)
{
	return num > 0 ? num : -num;
}

void Swap(int* num1, int* num2)
{
	int* temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

int Partition(int left, int right)
{
	int pivot = heights[left];
	int lowPointer = left + 1;
	int highPointer = right;

	while (lowPointer <= highPointer)
	{
		if (lowPointer <= right && pivot >= heights[lowPointer])
		{
			++lowPointer;
		}

		if (highPointer >= left && pivot <= heights[highPointer])
		{
			--highPointer;
		}

		if (lowPointer < highPointer)
		{
			Swap(&heights[lowPointer], &heights[highPointer]);
		}
	}
	Swap(&heights[left], &heights[highPointer]);
	return highPointer;
}

void QuickSort(int left, int right)
{
	if (left > right)
		return;
	int pivot = Partition(left, right);
	QuickSort(left, pivot - 1);
	QuickSort(pivot + 1, right);
}

int Solution()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &heights[i]);
	}
	QuickSort(0, N - 1);
	
	int mid = (N / 2);
	int leftPointer = mid;
	int rightPointer = mid;
	int heightsPointer = N - 1;

	result[mid] = heights[heightsPointer];
	while (heightsPointer >= 0)
	{
		leftPointer = (leftPointer == 0) ? (N - 1) : (leftPointer - 1);
		--heightsPointer;
		if (heightsPointer < 0)
		{
			break;
		}
		result[leftPointer] = heights[heightsPointer];

		rightPointer = (rightPointer + 1) % N;
		--heightsPointer;
		if (heightsPointer < 0)
		{
			break;
		}
		result[rightPointer] = heights[heightsPointer];
	}

	int maxDiff = 0;
	for (int i = 0; i < N - 1; ++i)
	{
		int diff = GetAbs(result[i] - result[i + 1]);
		maxDiff = (maxDiff > diff) ? maxDiff : diff;
	}
	int diff = GetAbs(result[N - 1] - result[0]);
	maxDiff = (maxDiff > diff) ? maxDiff : diff;
	return maxDiff;
}

int main(void)
{
	int T;
	scanf("%d", &T);
	for (int testCase = 0; testCase < T; ++testCase)
	{
		int maxDiff = Solution();
		printf("%d\n", maxDiff);
	}
	return 0;
}