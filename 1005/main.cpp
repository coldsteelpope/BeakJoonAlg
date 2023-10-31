#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> adjacentList;
vector<int> nDegrees;
vector<int> tot_costs;
vector<int> costs;

inline int GetMax(int a, int b)
{
	return a > b ? a : b;
}


void SetAdjacentList(int N, int K)
{
	adjacentList.resize(N + 1);
	costs.resize(N + 1);
	tot_costs.resize(N + 1);
	nDegrees.resize(N + 1, 0);

	for (int node = 1; node <= N; ++node)
	{
		cin >> costs[node];
	}

	for (int i = 0; i < K; ++i)
	{
		int start_node, target_node;
		cin >> start_node >> target_node;
		adjacentList[start_node].emplace_back(target_node);
		++nDegrees[target_node];
	}
}

int topologySort(int N, int target_node)
{
	queue<int> q;
	for (int node = 1; node <= N; ++node)
	{
		if (nDegrees[node] == 0)
		{
			q.emplace(node);
			tot_costs[node] = costs[node];
		}
	}


	while (q.empty() == false)
	{
		int here = q.front();

		q.pop();
		for (int there_idx = 0; there_idx < adjacentList[here].size(); ++there_idx)
		{
			int next_node = adjacentList[here][there_idx];
			
			tot_costs[next_node] = GetMax(tot_costs[next_node], tot_costs[here] + costs[next_node]);
			if (--nDegrees[next_node] == 0)
			{
				q.emplace(next_node);
			}
		}
	}

	return tot_costs[target_node];
}


int main(void)
{
	int T;
	cin >> T;

	for (int t = 0; t < T; ++t)
	{
		int N, K;
		cin >> N >> K;
		SetAdjacentList(N, K);
		int target_node;
		cin >> target_node;
		int result = topologySort(N, target_node);
		cout << result << endl;

		adjacentList.clear();
		nDegrees.clear();
		tot_costs.clear();
		costs.clear();
	}

	return 0;
}