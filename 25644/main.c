#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

unsigned long long int prices[200000];

int main(void)
{
	int N;
	scanf("%d", &N);
	for (int n = 0; n < N; ++n)
	{
		scanf("%lld", &prices[n]);
	}

	unsigned long long int answer = 0;
	unsigned long long int maxValue = prices[N - 1];
	for (int n = N - 1; n >= 0; --n)
	{
		unsigned long long int currentValue = prices[n];
		if (maxValue < currentValue)
		{
			maxValue = currentValue;
		}
		else
		{
			answer = ((maxValue - currentValue) > answer) ? (maxValue - currentValue) : answer;
		}
	}
	printf("%lld\n", answer);
	return 0;
}