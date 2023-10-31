#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#define INF 500000000

using namespace std;

vector<vector<pair<int, int>>> adjacentList;

// Return Distance From Start_POS
vector<int> BFS(int N, int start_pos)
{
	vector<int> dist(N + 1, INF);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	
	pq.push({ 0, start_pos });
	dist[start_pos] = 0;

	while (pq.empty() == false)
	{
		pair<int, int> here = pq.top();
		pq.pop();

		if (here.first > dist[here.second])
			continue;

		for (int there_idx = 0; there_idx < adjacentList[here.second].size(); ++there_idx)
		{
			pair<int, int> there = adjacentList[here.second][there_idx];
			int pathLen = dist[here.second] + there.first;

			if (pathLen < dist[there.second])
			{
				dist[there.second] = pathLen;
				pq.push({ pathLen, there.second });
			}
		}
	}

	return dist;
}

int GetPathOne(int v1, int v2, int N)
{
	int dist1 = BFS(N, 1)[v1];
	int dist2 = BFS(N, v1)[v2];
	int dist3 = BFS(N, v2)[N];

	if (dist1 == INF || dist2 == INF || dist3 == INF)
		return -1;
	else
		return dist1 + dist2 + dist3;
}

int GetPathTwo(int v1, int v2, int N)
{
	int dist1 = BFS(N, 1)[v2];
	int dist2 = BFS(N, v2)[v1];
	int dist3 = BFS(N, v1)[N];

	if (dist1 == INF || dist2 == INF || dist3 == INF)
		return -1;
	else
		return dist1 + dist2 + dist3;
}

int main(void)
{
	int N, E;
	cin >> N >> E;
	
	adjacentList.resize(N + 1);
	for (int i = 0; i < E; ++i)
	{
		int src, dest, weight;
		cin >> src >> dest >> weight;
		adjacentList[src].push_back({ weight, dest });
		adjacentList[dest].push_back({ weight, src });
	}

	int v1, v2;
	cin >> v1 >> v2;

	int path_one = GetPathOne(v1, v2, N);
	int path_two = GetPathTwo(v1, v2, N);
	int answer = (path_one > path_two) ? path_two : path_one;

	cout << answer << endl;
	return 0;
}