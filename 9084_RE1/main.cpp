#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	int T;
	cin >> T;
	for (int testCase = 0; testCase < T; ++testCase)
	{
		int N;
		cin >> N;
		vector<int> coins(N, 0);

		for (int n = 0; n < N; ++n)
		{
			cin >> coins[n];
		}

		int M;
		cin >> M;

		vector<int> dp(M + 1, 0);
		dp[0] = 1;
		for (int coin : coins)
		{
			for (int target = coin; target <= M; ++target)
			{
				// dp[target]: 현재 coin 이전의 코인들로 만들 수 있는 총 조합의 수
				// dp[target - coin]: 현재 coin을 넣기 위해 필요한 조합의 수
				dp[target] = dp[target] + dp[target - coin];
			}
		}
		cout << dp[M] << "\n";
	}
	return 0;
}