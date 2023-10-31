#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void)
{
	int coins[101] = { 0, };
	int dp[10001] = { 0, };

	int n, k;
	scanf("%d%d", &n, &k);
	
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &coins[i]);
	}

	dp[0] = 1;
	for (int coin_index = 0; coin_index < n; ++coin_index)
	{
		//int current_coin = coins[coin_index];
		//dp[current_coin] += 1;
		for (int i = coins[coin_index]; i <= k; ++i)
		{
			dp[i] = dp[i] + dp[i - coins[coin_index]];
		}
	}
	printf("%d", dp[k]);
	return 0;
}