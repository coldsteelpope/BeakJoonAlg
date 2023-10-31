#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

long long cards[1001] = { 0, };
long long temp[1001] = { 0, };

void MergeResult(long long left, long long mid, long long right)
{
	long long leftIdx = left;
	long long rightIdx = mid + 1;
	long long tempIdx = 0;

	while (leftIdx <= mid && rightIdx <= right)
	{
		if (cards[leftIdx] < cards[rightIdx])
			temp[tempIdx++] = cards[leftIdx++];
		else
			temp[tempIdx++] = cards[rightIdx++];
	}

	if (mid < leftIdx)
	{
		while (rightIdx <= right)
			temp[tempIdx++] = cards[rightIdx++];
	}
	else
	{
		while (leftIdx <= mid)
			temp[tempIdx++] = cards[leftIdx++];
	}

	for (long long i = 0; i < tempIdx; ++i)
		cards[left + i] = temp[i];
}

void MergeSort(long long left, long long right)
{
	if (left >= right)
		return;
	long long mid = (left + right) / 2;
	MergeSort(left, mid);
	MergeSort(mid + 1, right);
	MergeResult(left, mid, right);
}

int main(void)
{
	long long n, m;
	scanf("%lld%lld", &n, &m);

	for (long long i = 0; i < n; ++i)
		scanf("%lld", &cards[i]);

	for (long long i = 0; i < m; ++i)
	{
		MergeSort(0, n - 1);
		long long tot = cards[0] + cards[1];
		cards[0] = tot; cards[1] = tot;
	}

	long long tot = 0;
	for (long long i = 0; i < n; ++i)
		tot += cards[i];
	printf("%lld", tot);
	return 0;
}