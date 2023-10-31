#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int A[51] = { 0, };
int B[51] = { 0, };
int temp[51] = { 0, };

// B는 내림차순 정렬
void BResult(int left, int mid, int right)
{
	int leftIdx = left;
	int rightIdx = mid + 1;
	int tempIdx = 0;

	while (leftIdx <= mid && rightIdx <= right)
	{
		if (B[leftIdx] > B[rightIdx])
		{
			temp[tempIdx++] = B[leftIdx++];
		}
		else
		{
			temp[tempIdx++] = B[rightIdx++];
		}
	}

	if (mid < leftIdx)
	{
		while (rightIdx <= right)
		{
			temp[tempIdx++] = B[rightIdx++];
		}
	}
	else
	{
		while (leftIdx <= mid)
		{
			temp[tempIdx++] = B[leftIdx++];
		}
	}

	for (int i = 0; i < tempIdx; ++i)
	{
		B[left + i] = temp[i];
	}
}

void BSort(int left, int right)
{
	if (left >= right)
		return;
	int mid = (left + right) / 2;
	BSort(left, mid);
	BSort(mid + 1, right);
	BResult(left, mid, right);
}

// A는 오름차순 정렬
void AResult(int left, int mid, int right)
{
	int leftIdx = left;
	int rightIdx = mid + 1;
	int tempIdx = 0;

	while (leftIdx <= mid && rightIdx <= right)
	{
		if (A[leftIdx] <= A[rightIdx])
		{
			temp[tempIdx++] = A[leftIdx++];
		}
		else
		{
			temp[tempIdx++] = A[rightIdx++];
		}
	}

	if (mid < leftIdx)
	{
		while (rightIdx <= right)
		{
			temp[tempIdx++] = A[rightIdx++];
		}
	}
	else
	{
		while (leftIdx <= mid)
		{
			temp[tempIdx++] = A[leftIdx++];
		}
	}

	for (int i = 0; i < tempIdx; ++i)
	{
		A[left + i] = temp[i];
	}
}

void ASort(int left, int right)
{
	if (left >= right)
		return;
	int mid = (left + right) / 2;
	ASort(left, mid);
	ASort(mid + 1, right);
	AResult(left, mid, right);
}

int main(void)
{
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &A[i]);
	}

	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &B[i]);
	}

	ASort(0, N - 1);
	BSort(0, N - 1);
	
	int sum = 0;
	for (int i = 0; i < N; ++i)
	{
		int result = A[i] * B[i];
		sum += result;
	}
	printf("%d", sum);
	return 0;
}