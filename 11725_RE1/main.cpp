#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<vector<int>> adjacentList;

// discovered 배열을 사용해도 좋지만
// parents 배열을 사용해서, 방문 여부를 확인할 수 있다.
// 예를 들어, 0이면 방문하지 않은 노드, 0이 아닌 다른 수면 방문한 노드

vector<bool> discovered;
vector<int> parents;

void SetAdjacentList(int N)
{
	adjacentList.resize(N + 1);
	discovered.resize(N + 1, false);
	parents.resize(N + 1, 0);

	for (int n = 0; n < N - 1; ++n)
	{
		int start, target;
		cin >> start >> target;
		adjacentList[start].emplace_back(target);
		adjacentList[target].emplace_back(start);
	}
}

int main(void)
{
	int N; cin >> N;
	SetAdjacentList(N);

	queue<int> q;
	q.push(1);
	discovered[1] = true;
	
	while (q.empty() == false)
	{
		int parent = q.front();
		q.pop();

		for (int thereIdx = 0; thereIdx < adjacentList[parent].size(); ++thereIdx)
		{
			int there = adjacentList[parent][thereIdx];
			if (discovered[there] == true)
			{
				continue;
			}
			discovered[there] = true;
			parents[there] = parent;
			q.push(there);
		}
	}
	
	for (int node = 2; node <= N; ++node)
	{
		cout << parents[node] << "\n";
	}
	return 0;
}