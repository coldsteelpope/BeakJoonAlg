#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<vector<int>> adjacentList;
vector<int> dis;
map<int, bool> visited;

int distance = 0;
void DFS(int here, int target, int path)
{
	if (visited[here] == true)
		return;
	
	visited[here] = true;
	dis[here] = path;

	for (int there_idx = 0; there_idx < adjacentList[here].size(); ++there_idx)
	{
		int there = adjacentList[here][there_idx];
		if (visited[there] == true)
			continue;
		DFS(there, target, path + 1);
	}
}

int main(void)
{
	int n;
	cin >> n;
	int target, start;
	cin >> target >> start;
	int m;
	cin >> m;

	adjacentList.resize(n + 1);
	dis.resize(n + 1, -1);

	for (int i = 0; i < m; ++i)
	{
		int parent, child;
		cin >> parent >> child;
		adjacentList[parent].push_back(child);
		adjacentList[child].push_back(parent);
	}
	
	DFS(start, target, 0);
	cout << dis[target] << endl;
	return 0;
}