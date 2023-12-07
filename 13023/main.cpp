#include <iostream>
#include <vector>

#define MAX_RELATED_NUM 5

using namespace std;

vector<vector<int>> adjacentList;
vector<bool> visited;

void DFS(int here, int count)
{
	if (count == MAX_RELATED_NUM)
	{
		// 종료 조건을 여기서 바로 종료하게 했더니 통과했다. 더 좋은 방법은?
		cout << 1 << "\n";
		exit(0);
	}
	
	for (int thereIdx = 0; thereIdx < adjacentList[here].size(); ++thereIdx)
	{
		int there = adjacentList[here][thereIdx];
		if (visited[there] == true)
		{
			continue;
		}
		visited[there] = true;
		DFS(there, count + 1);
		visited[there] = false;
	}
	// 조건이 맞지 않으면 해당 노드의 visited를 false로 바꿔줘야한다.
	// 그 이유는 지금과 다른 순서 조건으로 해당 노드를 방문할 수 있기 때문이다.
	/*
	반례)
	5 6
	0 1
	1 4
	1 2
	1 3
	2 4
	3 4
	output: 0
	answer: 1
	*/
}

void Check(int N)
{
	for (int node = 0; node < N; ++node)
	{
		visited.resize(N);
		visited[node] = true;
		DFS(node, 1);
		visited.clear();
	}
	cout << 0 << "\n";
}

void SetAdjacentList(int N, int M)
{
	adjacentList.resize(N);
	for (int i = 0; i < M; ++i)
	{
		int start, target;
		cin >> start >> target;
		adjacentList[start].emplace_back(target);
		adjacentList[target].emplace_back(start);
	}
}

int main(void)
{
	int N, M;
	cin >> N >> M;
	SetAdjacentList(N, M);
	Check(N);
	return 0;
}