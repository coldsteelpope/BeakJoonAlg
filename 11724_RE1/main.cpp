#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adjacentList;
vector<bool> visited;

void DFS(int node)
{
	visited[node] = true;
	for (int thereIdx = 0; thereIdx < adjacentList[node].size(); ++thereIdx)
	{
		int there = adjacentList[node][thereIdx];
		if (visited[there] == true)
		{
			continue;
		}
		DFS(there);
	}
}

int main(void)
{
	int N, M;
	cin >> N >> M;

	adjacentList.resize(N + 1);
	visited.resize(N + 1, false);

	for (int i = 0; i < M; ++i)
	{
		int start, target;
		cin >> start >> target;
		adjacentList[start].emplace_back(target);
		adjacentList[target].emplace_back(start);
	}

	int answer = 0;
	for (int node = 1; node <= N; ++node)
	{
		if (visited[node] == true)
		{
			continue;
		}
		DFS(node);
		++answer;
	}
	cout << answer << "\n";
	return 0;
}