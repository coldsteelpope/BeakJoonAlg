#include <iostream>
#include <vector>

using namespace std;

vector<int> coins;
int dp[10001] = { 0, };

void ClearDP()
{
	for (int i = 0; i <= 10000; ++i)
		dp[i] = 0;
}

int main(void)
{
	int T; cin >> T;
	for (int t = 0; t < T; ++t)
	{
		int N; cin >> N;
		for (int n = 0; n < N; ++n)
		{
			int coin; cin >> coin;
			coins.push_back(coin);
		}
		int M; cin >> M;

		dp[0] = 1;
		for (int coinsIdx = 0; coinsIdx < coins.size(); ++coinsIdx)
		{
			for (int j = coins[coinsIdx]; j <= M; ++j)
			{
				dp[j] += dp[j - coins[coinsIdx]];
			}
		}
		cout << dp[M] << endl;
		ClearDP();
		coins.clear();
	}
	
	return 0;
}