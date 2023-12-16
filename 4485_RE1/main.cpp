#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

vector<vector<int>> cost;
vector<vector<int>> dp;

int SetCostAndDP(int N)
{
	cost.clear();
	dp.clear();

	cost.resize(N, vector<int>(N, 0));
	dp.resize(N, vector<int>(N, 0));

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> cost[i][j];
			dp[i][j] = (~0U >> 2);
		}
	}

	return N;
}

void PrintDP(int N)
{
	cout << endl;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cout << dp[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}

int Solution(int N)
{
	SetCostAndDP(N);
	//priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>> pq;
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
	pq.push({ cost[0][0], {0,0} });
	
	int dirs[4][2] = {
		{ +0, +1 },
		{ +1, +0 },
		{ +0, -1 },
		{ -1, +0 }
	};

	while (pq.empty() == false)
	{
		pair<int, pair<int, int>> here = pq.top();
		pq.pop();

		//if (here.first > dp[here.second.first][here.second.second])
		//{
		//	continue;
		//}

		for (int dirIdx = 0; dirIdx < 4; ++dirIdx)
		{
			int nextY = here.second.first + dirs[dirIdx][0];
			int nextX = here.second.second + dirs[dirIdx][1];
			if (nextY < 0 || nextX < 0 || nextY >= N || nextX >= N)
			{
				continue;
			}

			int nextCost = here.first + cost[nextY][nextX];
			if (nextCost < dp[nextY][nextX])
			{
				dp[nextY][nextX] = nextCost;
				pq.push({ nextCost, {nextY, nextX} });
			}
		}

		//PrintDP(N);
	}
	return dp[N - 1][N - 1];
}

int main(void)
{
	int count = 1;
	int N;
	while (1)
	{
		cin >> N;
		if (N == 0)
		{
			break;
		}
		int answer = Solution(N);
		cout << "Problem " << count << ": " << answer << "\n";
		++count;
	}
	return 0;
}