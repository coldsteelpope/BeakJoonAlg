#include <iostream>
#include <vector>

using namespace std;

vector<long long> stock_prices;

int main(void)
{
	long long T;
	cin >> T;

	for (int t = 0; t < T; ++t)
	{
		long long stock_prices_len = 0;
		cin >> stock_prices_len;

		for (long long i = 0; i < stock_prices_len; ++i)
		{
			long long stock_price;
			cin >> stock_price;
			stock_prices.push_back(stock_price);
		}

		long long revenue = 0;
		long long max_stock_price = stock_prices[stock_prices.size() - 1];
		for (long long stock_prices_idx = stock_prices.size() - 2; stock_prices_idx >= 0; --stock_prices_idx)
		{
			if (stock_prices[stock_prices_idx] >= max_stock_price)
			{
				max_stock_price = stock_prices[stock_prices_idx];
			}
			else
			{
				revenue += (max_stock_price - stock_prices[stock_prices_idx]);
			}
		}

		cout << revenue << endl;
		stock_prices.clear();

	}


	return 0;
}