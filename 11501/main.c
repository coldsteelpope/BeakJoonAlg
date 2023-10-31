#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

long long stock_prices[10001] = { 0, };
long long owned_stocks[10001] = { 0, };
long long owned_stock_len = 0;

int main(void)
{
	long long T = 0;
	scanf("%lld", &T);

	for (long long t = 0; t < T; ++t)
	{
		long long N;
		scanf("%lld", &N);

		for (long long i = 0; i < N; ++i)
			scanf("%lld", &stock_prices[i]);

		long long revenue = 0;

		for (long long day = 0; day < N - 1; ++day)
		{
			if (stock_prices[day] <= stock_prices[day + 1])
			{
				owned_stocks[owned_stock_len++] = stock_prices[day];
			}
			else
			{
				long long current_stock_price = stock_prices[day];
				for (long long owned_stock_idx = 0; owned_stock_idx < owned_stock_len; ++owned_stock_idx)
				{
					revenue += (current_stock_price - owned_stocks[owned_stock_idx]);
				}
				owned_stock_len = 0;
			}
		}

		if (owned_stock_len > 0)
		{
			long long current_stock_price = stock_prices[N - 1];
			for (long long owned_stock_idx = 0; owned_stock_idx < owned_stock_len; ++owned_stock_idx)
			{
				revenue += (current_stock_price - owned_stocks[owned_stock_idx]);
			}
		}

		printf("%lld\n", revenue);
		owned_stock_len = 0;
	}


	return 0;
}