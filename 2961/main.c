#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _STUFF
{
	long long int _sour;
	long long int _salty;
} Stuff;

Stuff stuffs[11] = { 0, };
bool visited[11] = { 0, };

long long int result = 9223372036854775807;

long long int GetAbs(long long int a)
{
	return a > 0 ? a : -a;
}

long long int GetMin(long long int a, long long int b)
{
	return a > b ? b : a;
}

void Combination(int count, int maxCount, int sumResult, int mulResult, int N)
{
	if (count == maxCount)
	{
		result = GetMin(result, GetAbs(sumResult - mulResult));
		return;
	}
	else
	{
		for (int i = 0; i < N; ++i)
		{
			if (visited[i] == true)
				continue;
			visited[i] = true;
			Combination(count + 1, maxCount, sumResult + stuffs[i]._salty, mulResult * stuffs[i]._sour, N);
			visited[i] = false;
		}
	}
}

int main(void)
{
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; ++i)
	{
		scanf("%lld%lld", &stuffs[i]._sour, &stuffs[i]._salty);
	}

	for (int maxCount = 1; maxCount <= N; ++maxCount)
	{
		Combination(0, maxCount, 0, 1, N);
	}
	printf("%lld\n", result);
	return 0;
}