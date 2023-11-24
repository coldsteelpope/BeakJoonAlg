#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LEN 20000

int A[MAX_LEN] = { 0, };
int B[MAX_LEN] = { 0, };
int temp[MAX_LEN] = { 0, };

void AMergeResult(int left, int mid, int right)
{
	int leftPointer = left;
	int rightPointer = mid + 1;
	int tempIdx = 0;

	while (leftPointer <= mid && rightPointer <= right)
	{
		if (A[leftPointer] >= A[rightPointer])
		{
			temp[tempIdx++] = A[leftPointer++];
		}
		else
		{
			temp[tempIdx++] = A[rightPointer++];
		}
	}

	if (mid < leftPointer)
	{
		while (rightPointer <= right)
		{
			temp[tempIdx++] = A[rightPointer++];
		}
	}
	else
	{
		while (leftPointer <= mid)
		{
			temp[tempIdx++] = A[leftPointer++];
		}
	}

	for (int i = 0; i < tempIdx; ++i)
	{
		A[left + i] = temp[i];
	}
}

void AMergeSort(int left, int right)
{
	if (left >= right)
		return;
	int mid = (left + right) / 2;
	AMergeSort(left, mid);
	AMergeSort(mid + 1, right);
	AMergeResult(left, mid, right);
}

void BMergeResult(int left, int mid, int right)
{
	int leftPointer = left;
	int rightPointer = mid + 1;
	int tempIdx = 0;

	while (leftPointer <= mid && rightPointer <= right)
	{
		if (B[leftPointer] <= B[rightPointer])
		{
			temp[tempIdx++] = B[leftPointer++];
		}
		else
		{
			temp[tempIdx++] = B[rightPointer++];
		}
	}

	if (mid < leftPointer)
	{
		while (rightPointer <= right)
		{
			temp[tempIdx++] = B[rightPointer++];
		}
	}
	else
	{
		while (leftPointer <= mid)
		{
			temp[tempIdx++] = B[leftPointer++];
		}
	}

	for (int i = 0; i < tempIdx; ++i)
	{
		B[left + i] = temp[i];
	}
}

void BMergeSort(int left, int right)
{
	if (left >= right)
		return;
	int mid = (left + right) / 2;
	BMergeSort(left, mid);
	BMergeSort(mid + 1, right);
	BMergeResult(left, mid, right);
}

void Solution()
{
	int N, M;
	scanf("%d%d", &N, &M);

	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &A[i]);
	}

	for (int i = 0; i < M; ++i)
	{
		scanf("%d", &B[i]);
	}

	AMergeSort(0, N - 1);
	BMergeSort(0, M - 1);

	int answer = 0;
	int BminValue = B[0];
	for (int Apointer = 0; Apointer < N; ++Apointer)
	{
		if (A[Apointer] <= BminValue)
		{
			break;
		}
		for (int Bpointer = 0; Bpointer < M; ++Bpointer)
		{
			if (A[Apointer] <= B[Bpointer])
			{
				break;
			}
			++answer;
		}
	}
	printf("%d\n", answer);
}

int main(void)
{
	int T;
	scanf("%d", &T);
	for (int testCase = 0; testCase < T; ++testCase)
	{
		Solution();
	}
	return 0;
}