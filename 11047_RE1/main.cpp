#include <iostream>
#include <vector>

using namespace std;

vector<int> coins;

int main(void)
{
	int N, K;
	cin >> N >> K;
	
	coins.resize(N, 0);
	for (int i = 0; i < N; ++i)
	{
		cin >> coins[i];
	}

	int answer = 0;
	for (int coinIdx = N - 1; coinIdx >= 0; --coinIdx)
	{
		int currentCoin = coins[coinIdx];
		if (K < currentCoin)
		{
			continue;
		}
		while (K >= currentCoin)
		{
			K -= currentCoin;
			++answer;
		}
	}

	cout << answer << "\n";
	return 0;
}