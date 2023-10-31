#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _NODE
{
	int _cost;
	int _weight;
} Node;

Node card_packs[1001] = { 0, };
int dp[1001][1001] = { 0, };

int GetMax(int a, int b)
{
	return a > b ? a : b;
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

	for (int k = 1; k <= N; ++k)
	{
		int card_pack_cost = card_packs[k]._cost;
		int card_pack_weight = card_packs[k]._weight;

		for (int weight = 1; weight <= N; ++weight)
		{
			if (card_pack_weight > weight)
			{
				dp[weight][k] = dp[weight][k - 1];
			}
			else
			{
				dp[weight][k] = GetMax(dp[weight][k - 1], dp[weight - card_pack_weight][k] + card_pack_cost);
			}
		}
	}

	printf("%d", dp[N][N]);
	return 0;
}