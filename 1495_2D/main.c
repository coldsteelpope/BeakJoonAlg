#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int volumes[51] = { 0, };

bool dp[101][1001] = { 0, };

int GetMax(int a, int b)
{
	return a > b ? a : b;
}

void SetDP(int N, int M, int S)
{
	dp[0][S] = 1;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 0; j <= M; ++j)
		{
			if (dp[i - 1][j] == true)
			{
				if (j - volumes[i] >= 0 && j - volumes[i] <= M)
				{
					dp[i][j - volumes[i]] = 1;
				}
				
				if(j + volumes[i] >= 0 && j + volumes[i] <= M)
				{
					dp[i][j + volumes[i]] = 1;
				}
			}
		}
	}
}

int main(void)
{
	int N, S, M;
	scanf("%d%d%d", &N, &S, &M);

	for (int i = 1; i <= N; ++i)
		scanf("%d", &volumes[i]);

	SetDP(N, M, S);

	int max_volume = -1;
	for (int v = 0; v <= M; ++v)
	{
		if (dp[N][v] == 1)
			max_volume = v;
	}

	printf("%d", max_volume);
	return 0;
}