#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int InDegrees[1003] = { 0, };
map<int, int> dp;
map<int, int> cost;

int main(void)
{
	int N, a, b, M, c, d, T, K, W;
	int x, y, node_cost;

	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		int answer = 0;
		cin >> N >> K;
		vector<vector<int>> v(N + 1);
		queue<int> q;

		for (int j = 1; j <= N; ++j)
		{
			cin >> node_cost;
			cost[j] = node_cost;
			dp[j] = node_cost;
		}


	}
}