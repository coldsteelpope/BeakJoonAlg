#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _CARD
{
	int _weight;
	int _cost;
} Card;

Card card_packs[1001] = { 0, };
int dp[1001][1001] = { 0, };

int GetMax(int a, int b)
{
	return a > b ? a : b;
}

int GetMin(int a, int b)
{
	return a < b ? a : b;
}

int main(void)
{
	int N;
	scanf("%d", &N);

	for (int i = 1; i <= N; ++i)
	{
		scanf("%d", &card_packs[i]._cost);
		card_packs[i]._weight = i;
	}

	for (int weight = 1; weight <= N; ++weight)
	{
		int current_weight = card_packs[1]._weight;
		int current_cost = card_packs[1]._cost;
		if (current_weight > weight)
		{
			dp[weight][1] = dp[weight][0];
		}
		else
		{
			dp[weight][1] = GetMax(dp[weight][0], dp[weight - current_weight][1] + current_cost);
		}
	}

	for (int k = 2; k <= N; ++k)
	{
		int current_weight = card_packs[k]._weight;
		int current_cost = card_packs[k]._cost;

		for (int weight = 1; weight <= N; ++weight)
		{
			if (current_weight > weight)
			{
				dp[weight][k] = dp[weight][k - 1];
			}
			else
			{
				dp[weight][k] = GetMin(dp[weight][k - 1], dp[weight - current_weight][k] + current_cost);
			}
		}
	}

	printf("%d", dp[N][N]);
	return 0;
}