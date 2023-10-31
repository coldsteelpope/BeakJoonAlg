#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int coin_values[11] = { 0, };
int main(void)
{
	int N, K;
	scanf("%d%d", &N, &K);
	
	for (int i = 0; i < N; ++i)
		scanf("%d", &coin_values[i]);
	
	int answer = 0;
	int coin_values_index = N - 1;
	while (K != 0)
	{
		int current_coin_values = coin_values[coin_values_index];
		if (K % current_coin_values == K)
		{
			--coin_values_index;
			continue;
		}
		else
		{
			while (K >= current_coin_values)
			{
				K -= current_coin_values;
				++answer;
			}
			--coin_values_index;
		}
	}
	printf("%d", answer);
	return 0;
}