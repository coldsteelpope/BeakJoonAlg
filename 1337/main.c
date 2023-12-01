// 밑의 코드와 다른 결과 값을 출력하는 반례
// N = 6
// arr = [1,7,9,12,18,20]

// lowPointer = 7, highPointer = 12일 때,
// 오답인 코드는 올바른 배열이라고 착각한다.
// arr = [7,8,9,10,11] 인데 12까지 세어버린다.
// 따라서, arr[highPointer] - arr[lowPointer] < 5로 변경했다. (전에는 <=)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

long long int arr[50] = { 0, };

long long int GetMax(long long int a, long long int b)
{
	return a > b ? a : b;
}

void SwapNum(long long int* num1, long long int* num2)
{
	long long int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

int Partition(int left, int right)
{
	long long int pivot = arr[left];
	int lowPointer = left + 1;
	int highPointer = right;

	while (lowPointer <= highPointer)
	{
		while (lowPointer <= right && pivot >= arr[lowPointer])
		{
			++lowPointer;
		}

		while (highPointer > left && pivot <= arr[highPointer])
		{
			--highPointer;
		}

		if (lowPointer < highPointer)
		{
			SwapNum(&arr[lowPointer], &arr[highPointer]);
		}
	}

	SwapNum(&arr[left], &arr[highPointer]);
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

int main(void)
{
	long long int N;
	scanf("%lld", &N);

	for (long long int n = 0; n < N; ++n)
	{
		scanf("%lld", &arr[n]);
	}

	QuickSort(0, N - 1);

	long long int maxValue = 0;
	long long int lowPointer = 0;
	long long int highPointer = 0;

	while (lowPointer <= highPointer)
	{
		if (highPointer == N - 1)
		{
			if (arr[highPointer] - arr[lowPointer] < 5)
			{
				maxValue = GetMax((highPointer - lowPointer + 1), maxValue);
			}
			++lowPointer;
		}
		else
		{
			if (arr[highPointer] - arr[lowPointer] < 5)
			{
				maxValue = GetMax((highPointer - lowPointer + 1), maxValue);
				++highPointer;
			}
			else
			{
				++lowPointer;
			}
		}
	}
	printf("%lld\n", 5 - maxValue);
	return 0;
}