#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int dp[100001][100] = { 0, };
int stuffs[101][2] = { 0, };

int GetMax(int a, int b)
{
	return a > b ? a : b;
}

int main(void)
{
	// N: 물품의 수
	// K: 준서가 버틸 수 있는 무게
	int N, K;
	scanf("%d%d", &N, &K);
	
	for (int i = 1; i <= N; ++i)
	{
		scanf("%d%d", &stuffs[i][0], &stuffs[i][1]);
	}

	for (int stuff_num = 1; stuff_num <= N; ++stuff_num)
	{
		int current_stuff_weight = stuffs[stuff_num][0];
		int current_stuff_value = stuffs[stuff_num][1];

		for (int weight = 1; weight <= K; ++weight)
		{
			if (current_stuff_weight > weight)
			{
				dp[weight][stuff_num] = dp[weight][stuff_num - 1];
			}
			else
			{
				dp[weight][stuff_num] = GetMax(dp[weight][stuff_num - 1], dp[weight - current_stuff_weight][stuff_num - 1] + current_stuff_value);
			}
		}
	}

	printf("%d", dp[K][N]);
	return 0;
}
