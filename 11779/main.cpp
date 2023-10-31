#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#define INF (~0U >> 2)

using namespace std;

vector<vector<pair<int, int>>> adjacentList;
vector<int> dist;
vector<int> parent;

int main(void)
{
	int n, m;
	cin >> n >> m;

	adjacentList.resize(n + 1);
	dist = vector<int>(n + 1, INF);
	parent = vector<int>(n + 1, -1);

	for (int i = 0; i < m; ++i)
	{
		int src, dest, weight;
		cin >> src >> dest >> weight;
		adjacentList[src].push_back({ weight, dest });
	}

	int start_node, target_node;
	cin >> start_node >> target_node;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, start_node });
	dist[start_node] = 0;

	while (pq.empty() == false)
	{
		pair<int, int> here = pq.top();
		pq.pop();

		if (here.first > dist[here.second])
			continue;

		for (int i = 0; i < adjacentList[here.second].size(); ++i)
		{
			pair<int, int> there = adjacentList[here.second][i];
			int pathLen = dist[here.second] + there.first;
			if (pathLen < dist[there.second])
			{
				dist[there.second] = pathLen;
				parent[there.second] = here.second;

				pq.push({ pathLen, there.second });
			}
		}
	}

	vector<int> cities;
	cities.push_back(target_node);
	int next_node = parent[target_node];
	while (next_node != -1)
	{
		cities.push_back(next_node);
		next_node = parent[next_node];
	}

	cout << dist[target_node] << endl;
	cout << cities.size() << endl;
	for (int i = cities.size() - 1; i >= 0; --i)
		cout << cities[i] << " ";

	return 0;
}