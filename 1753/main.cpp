#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

//vector<vector<pair<int, int>>> adjacent(20001);
//vector<int> pathLen(20001, (~0U >> 2));

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int V, E;
	cin >> V >> E;
	int K;
	cin >> K;

	vector<vector<pair<int, int>>> adjacent(V + 1);
	vector<int> pathLen(V + 1, (~0U >> 2));

	for (int i = 0; i < E; ++i)
	{
		int u, v, w;
		cin >> u >> v >> w;
		adjacent[u].push_back({ w, v });
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	// first => path
	// second => vertex_num
	pq.push({ 0, K });
	pathLen[K] = 0;
	
	while (pq.empty() == false)
	{
		pair<int, int> here = pq.top();
		pq.pop();

		if (here.first > pathLen[here.second])
			continue;
		
		for (int i = 0; i < adjacent[here.second].size(); ++i)
		{
			pair<int, int> there = adjacent[here.second][i];
			int path = here.first + there.first;


			if (pathLen[there.second] > path)
			{
				pathLen[there.second] = path;
				pq.push({ pathLen[there.second], there.second });
			}
			//pathLen[there.second] = (pathLen[there.second] > path) ? path : pathLen[there.second];
			//pq.push({ pathLen[there.second], there.second });
		}
	}

	for (int vertex = 1; vertex <= V; ++vertex)
	{
		if (pathLen[vertex] == (~0U >> 2))
			cout << "INF" << "\n";
		else
			cout << pathLen[vertex] << "\n";
	}
	return 0;
}