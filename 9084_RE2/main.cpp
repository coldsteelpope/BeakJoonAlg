#include <iostream>
#include <vector>
using namespace std;

void printDP(vector<vector<int>>& dp, int N, int M)
{
	cout << "--- DP TABLE ---" << endl;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j <= M; ++j)
		{
			cout << dp[i][j] << "\t";
		}
		cout << endl;
	}
}

void Solution()
{
	int N;
	cin >> N;

	vector<int> coins(N, 0);
	for (int i = 0; i < N; ++i)
	{
		cin >> coins[i];
	}

	int M;
	cin >> M;
	vector<vector<int>> dp;
	dp.resize(N, vector<int>(M + 1, 0));

	for (int coinIdx = 0; coinIdx < coins.size(); ++coinIdx)
	{
		dp[coinIdx][0] = 1;
	}

	for (int coinIdx = 0; coinIdx < coins.size(); ++coinIdx)
	{
		for (int targetCoin = coins[coinIdx]; targetCoin <= M; ++targetCoin)
		{
			dp[coinIdx][targetCoin] = dp[coinIdx][targetCoin] + dp[coinIdx][targetCoin - coins[coinIdx]];
		}

		if (coinIdx == coins.size() - 1)
			continue;

		for (int targetCoin = 1; targetCoin <= M; ++targetCoin)
		{
			dp[coinIdx + 1][targetCoin] = dp[coinIdx][targetCoin];
		}
	}
	cout << dp[N - 1][M] << "\n";
	dp.clear();
}

int main(void)
{
	int T;
	cin >> T;
	for (int testCase = 0; testCase < T; ++testCase)
	{
		Solution();
	}
	return 0;
}