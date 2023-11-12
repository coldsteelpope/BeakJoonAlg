#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adjacentList;
vector<bool> visited;

bool DFS(int here, int parent)
{
	visited[here] = true;
	for (int there_idx = 0; there_idx < adjacentList[here].size(); ++there_idx)
	{
		int there = adjacentList[here][there_idx];
		if (there == parent)
			continue;
		if (visited[there] == true)
			return true;
		if (DFS(there, here) == true)
			return true;
		
	}
	return false;
}

void PrintResult(int caseNum, int count)
{
	cout << "Case " << caseNum << ": ";
	if (count == 0)
		cout << "No trees." << endl;
	else if (count == 1)
		cout << "There is one tree." << endl;
	else
		cout << "A forest of " << count << " trees." << endl;
}

int main(void)
{
	int caseNum = 1;
	while (1)
	{
		int N, M; cin >> N >> M;
		if (N == 0 && M == 0)
			break;
		adjacentList.resize(N + 1);
		visited.resize(N + 1);
		for (int m = 0; m < M; ++m)
		{
			int start, target; cin >> start >> target;
			adjacentList[start].push_back(target);
			adjacentList[target].push_back(start);
		}

		int count = 0;
		for (int node = 1; node <= N; ++node)
		{
			if (visited[node] == true)
				continue;
			bool result = DFS(node, -1);
			if (result == false)
				++count;
		}
		PrintResult(caseNum, count);
		caseNum++;
		adjacentList.clear();
		visited.clear();
	}

	return 0;
}