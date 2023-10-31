#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

vector<vector<pair<int, int>>> adjacent(101);
vector<vector<int>> total_dis(101, vector<int>(101, (0)));

int bfs(int start_pos, int target_pos, int total_city_num)
{
	vector<int> dis(total_city_num + 1, (~0U >> 2));
	dis[start_pos] = 0;
	
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, start_pos });

	while (pq.empty() == false)
	{
		pair<int, int> here = pq.top();
		pq.pop();

		if (here.first > dis[here.second])
			continue;

		for (int there_index = 0; there_index < adjacent[here.second].size(); ++there_index)
		{
			pair<int, int> there = adjacent[here.second][there_index];
			int path = here.first + there.first;
			
			if (dis[there.second] > path)
			{
				dis[there.second] = path;
				pq.push({ dis[there.second], there.second });
			}
		}
	}

	if (dis[target_pos] == (~0U >> 2))
		return 0;
	else
		return dis[target_pos];
}

int main(void)
{
	// n: 도시(노드)
	// m: 버스(간선)
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n;
	cin >> m;

	for (int i = 0; i < m; ++i)
	{
		int start_city, target_city, cost;
		cin >> start_city >> target_city >> cost;
		adjacent[start_city].push_back({ cost, target_city });
	}
	
	for (int start_pos = 1; start_pos <= n; ++start_pos)
	{
		for (int target_pos = 1; target_pos <= n; ++target_pos)
		{
			total_dis[start_pos][target_pos] = bfs(start_pos, target_pos, n);
		}
	}

	for (int start_pos = 1; start_pos <= n; ++start_pos)
	{
		for (int target_pos = 1; target_pos <= n; ++target_pos)
		{
			cout << total_dis[start_pos][target_pos] << " ";
		}
		cout << "\n";
	}

	return 0;
}