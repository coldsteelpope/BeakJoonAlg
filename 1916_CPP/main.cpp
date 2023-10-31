#include <iostream>
#include <vector>
#include <queue>
#include <utility>

#define INF (~0U >> 2)

using namespace std;

vector<vector<pair<int, int>>> adjacentList;
vector<int> dist;

int main(void)
{
	int N, M;
	cin >> N >> M;
	
	adjacentList.resize(N + 1);
	dist = vector<int>(N + 1, INF);

	for (int t = 0; t < M; ++t)
	{
		int src, dest, weight;
		cin >> src >> dest >> weight;
		adjacentList[src].push_back({ weight, dest });
	}

	int start_pos, target_pos;
	cin >> start_pos >> target_pos;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, start_pos });
	dist[start_pos] = 0;
	
	while (pq.empty() == false)
	{
		pair<int, int> here = pq.top();
		int here_weight = here.first;
		int here_target = here.second;

		pq.pop();
		
		if (here_weight > dist[here_target])
			continue;
		
		for (int there_idx = 0; there_idx < adjacentList[here_target].size(); ++there_idx)
		{
			pair<int, int> there = adjacentList[here_target][there_idx];
			int there_weight = there.first;
			int there_target = there.second;

			int path = there_weight + dist[here_target];
			if (dist[there_target] > path)
			{
				dist[there_target] = path;
				pq.push({ path, there_target });
			}
		}
	}

	cout << dist[target_pos] << endl;
	return 0;
}