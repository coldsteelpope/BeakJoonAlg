#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int positions[100001] = { 0, };

bool IsPossible(int dist, int M, int N)
{
	int prev = 0;
	for (int stLightPosIdx = 0; stLightPosIdx < M; ++stLightPosIdx)
	{
		int stLightPos = positions[stLightPosIdx];
		// left-light
		if (stLightPos - dist <= prev)
		{
			// right-light
			prev = stLightPos + dist;
		}
		else
		{
			return false;
		}
	}

	if (N <= prev)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main(void)
{
	int N, M;
	scanf("%d", &N);
	scanf("%d", &M);
	for (int m = 0; m < M; ++m)
	{
		scanf("%d", &positions[m]);
	}

	int left = 0;
	int right = N;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (IsPossible(mid, M, N))
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
	printf("%d\n", left);
	return 0;
}