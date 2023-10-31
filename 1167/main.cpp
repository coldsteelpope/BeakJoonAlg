#include <iostream>
#include <vector>
#include <map>
#include <utility>

using namespace std;

vector<vector<pair<int, int>>> adjacent;
map<int, bool> visited;
int max_node = 0;
int max_path_len = 0;

void Dfs(int here, int pathLen)
{
	visited[here] = true;
	if (pathLen > max_path_len)
	{
		max_node = here;
		max_path_len = pathLen;
	}

	for (int there_index = 0; there_index < adjacent[here].size(); ++there_index)
	{
		pair<int, int> there = adjacent[here][there_index];
		if (visited[there.second] == true)
			continue;
		int newPathLen = pathLen + there.first;
		Dfs(there.second, newPathLen);
	}
}

int main(void)
{
	int V;
	cin >> V;
	adjacent = vector<vector<pair<int, int>>>(V + 1);

	for (int t = 0; t < V; ++t)
	{
		int headNode = 0;
		cin >> headNode;
		while (1)
		{
			int child, cost;
			cin >> child;
			if (child == -1)
				break;
			cin >> cost;
			adjacent[headNode].push_back({ cost, child });
		}
	}
	Dfs(1, 0);
	visited.clear();

	int temp_max_node = max_node;
	int temp_max_path_len = max_path_len;
	max_node = 0;
	max_path_len = 0;
	Dfs(temp_max_node, 0);

	cout << max_path_len << endl;
	return 0;
}