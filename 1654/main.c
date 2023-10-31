#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

long long arr[1000000] = { 0, };

int main(void)
{
	int K, N;
	scanf("%d%d", &K, &N);

	long long maxVal = 0;
	for (int i = 0; i < K; ++i)
	{
		scanf("%u", &arr[i]);
		if (maxVal < arr[i])
			maxVal = arr[i];
	}

	int count = 0;
	long long mid = 0;
	long long left = 1;
	long long right = maxVal;
	long long answer = 0;
	while (left <= right)
	{
		count = 0;
		mid = (left + right) / 2;
		for (long long i = 0; i < K; ++i)
		{
			count += arr[i] / mid;
		}
		if (count >= N)
		{
			if (answer < mid)
			{
				answer = mid;
			}
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	printf("%lld", answer);
}