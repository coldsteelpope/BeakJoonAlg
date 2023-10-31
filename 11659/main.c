#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

long long sum = 0;
long long sums[100001] = { 0, };
int sum_index = 1;

int main(void)
{
	int N, M;
	scanf("%d%d", &N, &M);

	sums[0] = 0;
	for (int t = 0; t < N; t++)
	{
		int num = 0;
		scanf("%d", &num);
		sums[sum_index] = sums[sum_index - 1] + num;
		++sum_index;
	}

	for (int t = 0; t < M; ++t)
	{
		int i, j;
		scanf("%d%d", &i, &j);
		printf("%lld\n", sums[j] - sums[i - 1]);
	}

	return 0;
}