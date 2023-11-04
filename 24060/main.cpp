#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int K = 0;
int K_num = 0;
int answer = -1;
int arr[500001] = { 0, };
int temp[500001] = { 0, };

void MergeResult(int left, int mid, int right)
{
	int leftIdx = left;
	int rightIdx = mid + 1;
	int tempIdx = 0;
	
	while (leftIdx <= mid && rightIdx <= right)
	{
		if (arr[leftIdx] < arr[rightIdx])
			temp[tempIdx++] = arr[leftIdx++];
		else
			temp[tempIdx++] = arr[rightIdx++];
	}

	if (leftIdx > mid)
	{
		while (rightIdx <= right)
			temp[tempIdx++] = arr[rightIdx++];
	}
	else
	{
		while (leftIdx <= mid)
			temp[tempIdx++] = arr[leftIdx++];
	}

	for (int i = 0; i < tempIdx; ++i)
	{
		++K_num;
		arr[left + i] = temp[i];
		if (K == K_num)
			answer = temp[i];
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

int main(void)
{
	int N;
	scanf("%d%d", &N, &K);

	for (int n = 0; n < N; ++n)
	{
		scanf("%d", &arr[n]);
	}
	MergeSort(0, N - 1);
	printf("%d\n", answer);
	return 0;
}